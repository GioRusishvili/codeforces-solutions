#include <bits/stdc++.h>
using namespace std;

const int N = 100005; // მასივის მაქსიმალური ზომა
const int B = 20; // ბიტების რაოდენობა (10^6 < 2^20)

int a[N]; // საწყისი მასივი(ინდექსაცია 1-დან)
int cnt[4 * N][B]; // cnt[node][b] = node-ის მონაკვეთში იმ ელემენტების რაოდენობა, სადაც b-ური ბიტი 1-ია
int lz[4 * N]; //XOR, რომელიც შვილებზე ჯერ არ გადაგვიცია

//მშობლის მნიშვნელობების გადათვლა ორი შვილის მიხედვით
//ერთების რაოდენობა მონაკვეთში = მარცხენა ნახევარში + მარჯვენა ნახევარში
void pull(int node) {
    for (int b = 0; b < B; b++) cnt[node][b] = cnt[2 * node][b] + cnt[2 * node + 1][b];
}

//node-ის მთელ მონაკვეთზე XOR-ის x მასკით გამოყენება
void applyMask(int node, int len, int x) {
    for (int b = 0; b < B; b++)
        if ((x >> b) & 1) //თუ x-ში b-ური ბიტი 1-ია,
            cnt[node][b] = len - cnt[node][b]; //ამ ბიტის ყველა მნიშვნელობა ტრიალდება
    lz[node] ^= x; //XOR-ები ერთმანეთს ერწყმის
}

//node-ის ლოდინის რეჟიმში მყოფი მასკის გადაცემა ორივე შვილზე
void push(int node, int l, int r) {
    if (lz[node] == 0) return; //გადასაცემი არაფერია
    int mid = (l + r) / 2;
    applyMask(2 * node,     mid - l + 1, lz[node]); //მარცხენა შვილი, სიგრძე mid-l+1
    applyMask(2 * node + 1, r - mid,     lz[node]); //მარჯვენა შვილი, სიგრძე r-mid
    lz[node] = 0; //ვასუფთავებთ
}

//ხის აგება საწყისი მასივიდან
void build(int node, int l, int r) {
    lz[node] = 0;
    if (l == r) {//ერთი ელემენტი
        for (int b = 0; b < B; b++)
            cnt[node][b] = (a[l] >> b) & 1; //ბიტის მნიშვნელობა თავადაა 0 ან 1
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid); //მარცხენა ნახევრის აგება
    build(2 * node + 1, mid + 1, r); //მარჯვენა ნახევრის აგება
    pull(node); //მშობლის გამოთვლა შვილებიდან
}

//[ql, qr] მონაკვეთის ყველა ელემენტზე XOR x
void update(int node, int l, int r, int ql, int qr, int x) {
    if (qr < l || r < ql) return; //გადაკვეთა არ არის: არაფერი იცვლება
    if (ql <= l && r <= qr) { //მთლიანად შიგნითაა
        applyMask(node, r - l + 1, x);
        return;
    }
    //ნაწილობრივი გადაკვეთა
    push(node, l, r); // ჯერ შვილებს ვაახლებთ
    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr, x);
    update(2 * node + 1, mid + 1, r, ql, qr, x);
    pull(node); // შვილები შეიცვალა, მშობელი თავიდან უნდა გადავთვალოთ
}

//[ql, qr] მონაკვეთის ჯამი
long long query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0; //გადაკვეთა არ არის
    if (ql <= l && r <= qr) { //მთლიანად შიგნითაა
        long long s = 0;
        for (int b = 0; b < B; b++)
            s += (long long)cnt[node][b] << b;
        return s;
    }
    //ნაწილობრივი გადაკვეთა: ჯერ push, შემდეგ ორივე შვილის პასუხების შეკრება
    push(node, l, r);
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n); //ხის აგება
    int m;
    cin >> m;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            //ჯამის გამოტანა
            cout << query(1, 1, n, l, r) << '\n';
        } else {
            //[l, r]-ზე XOR x
            int x;
            cin >> x;
            update(1, 1, n, l, r, x);
        }
    }
    return 0;
}