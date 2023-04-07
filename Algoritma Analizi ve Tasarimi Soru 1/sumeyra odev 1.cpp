#include <iostream>
#include <queue>
#include <vector>
#include <climits>


// Algoritma Analizi ve Tasarýmý KS-1 2.Ödev
// D* Algoritmasý
// Sümeyra Sümer
// 5210505067


using namespace std;

// pair ile kullanýlacak veri tipleri tanýmlanýyor
typedef pair<int, int> pii;// int tipinde iki veri
typedef pair<int, pii> pipii;// int ve pii tiplerinde veri

// Sabitler tanýmlanýyor
const int MAXN = 100005;// Grafýn maksimum düðüm sayýsý
const int INF = INT_MAX;// Sýnýrsýz büyüklükte bir sayý

// Düðümlere, kaynak ve hedefe iliþkin bilgileri tutacak diziler tanýmlanýyor
vector<pii> adj[MAXN];// Grafýn komþuluk listesi
int n, m, s, t, h[MAXN], g[MAXN], k[MAXN];/*n: düðüm sayýsý, m: kenar sayýsý, s: kaynak düðüm, 
t: hedef düðüm, h: h deðerleri, g: g deðerleri, k: k deðerleri*/

// Önceden tanýmlanmýþ priority_queue yapýsý kullanýlarak Dijkstra algoritmasý tanýmlanýyor
priority_queue<pipii, vector<pipii>, greater<pipii> > q;


// Dijkstra algoritmasýnýn uygulandýðý fonksiyon tanýmlanýyor
void dijkstra() {
	// Dizilerin ilk deðerleri atanýyor
    for (int i = 1; i <= n; ++i) {
        h[i] = INF;
        g[i] = INF;
    }
    h[t] = 0;
    q.push(make_pair(0, make_pair(t, 0)));
    while (!q.empty()) {
        int v = q.top().second.first;
        int k_old = q.top().second.second;
        q.pop();
        if (k_old != k[v]) continue;
        for (int i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i].first;
            int w = adj[v][i].second;
            if (g[u] > g[v] + w) {
                g[u] = g[v] + w;
                q.push(make_pair(g[u] + h[u], make_pair(u, k[u])));
            }
        }
        if (g[v] > h[v]) {
            g[v] = h[v];
            for (int i = 0; i < adj[v].size(); ++i) {
                int u = adj[v][i].first;
                int w = adj[v][i].second;
                if (h[u] > g[v] + w) {
                    h[u] = g[v] + w;
                    q.push(make_pair(h[u], make_pair(u, ++k[u])));
                }
            }
        }
    }
}

// Ana fonksiyon
int main() {
	
	cout << "Algoritma Analizi ve Tasarimi KS-1 2.Odev" << endl;
	cout << "D* Algoritmasi" << endl;
	cout << "Sumeyra Sumer" << endl;
	cout << "5210505067" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	
    cout << "Bu program, bir grafin belirli bir kaynaktan belirli bir hedefe en kisa yolu hesaplamak icin kullanilir." << endl;
    cout << "Lutfen grafin dugum sayisi, kenar sayisi, kaynak dugum ve hedef dugum degerlerini giriniz." << endl;
    cin >> n >> m >> s >> t;
    cout << "Lutfen " << m << " tane kenarin baslangic dugum, bitis dugum ve agirlik degerlerini giriniz:" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    dijkstra();
    cout << "Kaynak dugumden hedef dugume en kisa yolun uzunlugu: " << g[s] << endl;
    return 0;
}

