#include <iostream>
#include <queue>
#include <vector>
#include <climits>


// Algoritma Analizi ve Tasar�m� KS-1 2.�dev
// D* Algoritmas�
// S�meyra S�mer
// 5210505067


using namespace std;

// pair ile kullan�lacak veri tipleri tan�mlan�yor
typedef pair<int, int> pii;// int tipinde iki veri
typedef pair<int, pii> pipii;// int ve pii tiplerinde veri

// Sabitler tan�mlan�yor
const int MAXN = 100005;// Graf�n maksimum d���m say�s�
const int INF = INT_MAX;// S�n�rs�z b�y�kl�kte bir say�

// D���mlere, kaynak ve hedefe ili�kin bilgileri tutacak diziler tan�mlan�yor
vector<pii> adj[MAXN];// Graf�n kom�uluk listesi
int n, m, s, t, h[MAXN], g[MAXN], k[MAXN];/*n: d���m say�s�, m: kenar say�s�, s: kaynak d���m, 
t: hedef d���m, h: h de�erleri, g: g de�erleri, k: k de�erleri*/

// �nceden tan�mlanm�� priority_queue yap�s� kullan�larak Dijkstra algoritmas� tan�mlan�yor
priority_queue<pipii, vector<pipii>, greater<pipii> > q;


// Dijkstra algoritmas�n�n uyguland��� fonksiyon tan�mlan�yor
void dijkstra() {
	// Dizilerin ilk de�erleri atan�yor
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

