# algoritmaanalizivetasarimiodev2soru1


D* ALGORİTMASI


Algoritmanın Amacı


Bu algoritma, bir grafın belirli bir kaynaktan belirli bir hedefe en kısa yolu hesaplamak için kullanılır. D* algoritması olarak adlandırılan bu yöntem, Dijkstra algoritmasına dayanır ve grafa eklenen engellerin (örneğin, yeni bir düğümün eklenmesi veya bir düğümün hareket edilemez hale gelmesi gibi) güncellenmesi durumunda daha etkili bir şekilde çalışır. Algoritma, her düğüme özel olarak tutulan h, g ve k değerleri kullanır ve bu değerlerin güncellenmesi sayesinde en kısa yolun hesaplanması daha hızlı bir şekilde gerçekleştirilir.


Algoritma Ne İçin Kullanılır/Kullanılabilir?


Bu algoritma, bir grafın belirli bir kaynaktan belirli bir hedefe en kısa yolu hesaplamak için kullanılabilir. D* algoritması olarak adlandırılan bu yöntem, genişletilmiş A* algoritmasının bir türevidir. D* algoritması, A* algoritmasından farklı olarak, grafın düğümlerindeki hedef fonksiyonu h değerlerini güncellemek için bir mekanizma kullanır ve böylece daha verimli bir yol hesaplaması yapar. Bu nedenle, D* algoritması, dinamik bir çevre koşulu altında, yani graf yapısındaki değişikliklere uyum sağlamak için uygulanabilir. Ayrıca, yüksek boyutlu graf yapısı için de uygulanabilir.


Algoritmanın Çalışma Şekli


Bu algoritma D* algoritmasıdır ve bir grafın belirli bir kaynaktan belirli bir hedefe en kısa yolunu hesaplamak için kullanılır. Algoritma, Dijkstra algoritmasına benzer şekilde çalışır ve Dijkstra algoritmasına bir takım iyileştirmeler ekler. Bu iyileştirmeler, graf değişiklikleri olduğunda algoritmanın daha verimli bir şekilde çalışmasını sağlar.
Algoritma, öncelikle Dijkstra algoritması gibi çalışır ve grafın en kısa yollarını hesaplar. Ancak, D* algoritması ayrıca her bir düğümün güncellenmiş bir maliyetini de tutar. Algoritma, graf değişiklikleri olduğunda önceden hesaplanmış olan yolları kullanarak, hesaplama yapmadan önce güncellenmiş maliyetleri kontrol eder. Bu sayede, önceden hesaplanmış yolları kullanarak daha verimli bir şekilde çalışır ve daha az hesaplama yapar.
Algoritmanın çalışma şekli özetle şöyledir:
1.	Başlangıç düğümüne en kısa yolu 0 olarak ayarla, diğer düğümlere sonsuz olarak ayarla.
2.	Hedef düğüme en kısa yolu hesapla. Hedef düğümden başla ve Dijkstra algoritmasını uygula. Bu sırada her düğüm için h değeri hesaplanır.
3.	Dijkstra algoritması sonucunda, hedef düğüme en kısa yolu bulmuş olursun. Hedef düğümdeki maliyeti g'ye kaydet.
4.	Tüm düğümlerdeki k, g ve h değerlerini saklayın.
5.	Eğer g[v] > h[v], v'nin g maliyeti h maliyetine eşitlenir. Bu durumda, her bir v komşusunda, h maliyetinin güncellenip güncellenmeyeceğini kontrol etmek için Dijkstra algoritması uygulanır ve k değeri arttırılır. Bu işlem, eğer g[v] > h[v] ise yapılır.
6.	Yineleme, kaynak düğüme kadar devam eder ve kaynak düğümden hedef düğüme en kısa yol hesaplanır.
Algoritma, birçok farklı alanda kullanılabilir, özellikle robotikte ve yapay zeka alanlarında yaygın olarak kullanılmaktadır.


Algoritmanın Çalışma Durumu Analizi 

D* algoritması, bir grafın belirli bir kaynaktan belirli bir hedefe en kısa yolunu bulmak için kullanılır. Bu algoritmanın çalışma durumu analizi şu şekildedir:

•	En iyi durum: En iyi durumda, D* algoritması sadece bir kere çalıştırılır ve kaynak düğümden hedef düğüme en kısa yol bulunur. Bu durumda, algoritmanın zaman ve hafıza karmaşıklığı O(m log n) olacaktır, burada m kenar sayısı, n ise düğüm sayısıdır.

•	En kötü durum: En kötü durumda, algoritma ağaç yapıları veya döngüler içeren bir grafda çalıştırılır. Bu durumda, her bir düğüm en az bir kez işlenir ve her bir düğüm için komşuları kontrol edilir. Bu nedenle, algoritmanın zaman karmaşıklığı O(nm log n) olacaktır.

•	Ortalama durum: Ortalama durumda, grafın yapısına ve işlem yapılacak düğüm ve kenar sayısına bağlıdır. Bu durumda, D* algoritmasının zaman ve hafıza karmaşıklığı, O(m log n) ile O(nm log n) arasında olacaktır.
D* algoritması, genellikle ağaç yapısı veya seyrek graf gibi düşük düğüm ve kenar sayısına sahip grafiklerde daha iyi performans gösterir. Ancak, yoğun bir grafikte veya tam bir grafikte çalıştırıldığında, yüksek hafıza kullanımı nedeniyle performans sorunları ortaya çıkabilir.


