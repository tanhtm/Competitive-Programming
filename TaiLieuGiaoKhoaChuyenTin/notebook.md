# Kiến thức cơ bản
1. Số nguyên tố.
   - Nếu p là số nguyên tố và a là số tự nhiên *thì* 
    $$ 
    a^p \mod p = a 
    $$

2. Ước số, bội số. 
  
    2.1 $N$ được phân tích thành thừa số nguyên tố như sau:
    $$
    N = a^i * b^j * ... * c^k 
    $$
   - **Số ước** của N là:
    $$ 
    (i+1)*(j+1)...(k+1)
    $$
   - **Tổng ước**:
    $$
    F(N) = \frac{a^{i+1}-1}{a-1}*\frac{b^{j+1}-1}{b-1}*...*\frac{c^{k+1}-1}{c-1}
    $$
    2.2 Ước chung, bội chung
    - **Ước chung lớn nhất**: 
    $$
    ucln(a,b) = ucln(b,a\mod b)
    $$
    - **Bội chung nhỏ nhất**:
    $$
    bcnn(a,b) = \frac{a*b}{ucln(a,b)}
    $$
3. Lý thuyết tập hợp
    
    3.1  Tính chất phép toán tập hợp
    - Kết hợp
    - Giao hoán
    - Phân phối
    - Đối ngẫu
      - $\overline {A \cup B } = \overline {A} \cap \overline {B}$
      - $\overline {A \cap B } = \overline {A} \cup \overline {B}$
  
    3.2 Chỉnh hợp
    $$
    A_n ^ k = n(n-1)..(n-k+1) = \frac{n!}{(n-k)!}
    $$
    3.3 Tổ hợp
    $$
    C_n^k = \frac{n(n-1)..(n-k+1)}{k!} = \frac{n!}{k!(n-k)!}
    $$
    - Tính chất:
      - $C_n^k = C_n^{n-k}$
      - $C_n^0 = C_n^n = 1$
      - $C_n^k = C_{n-1}^{k-1} + C_{n-1}^k$
4. Số Fibonacci
   - $F_0 = 0$
   - $F_1 = 1$
   - $F_n = F_{n-1} + F_{n-2}$ 
   - Công thức tổng quát:
    $$
    F_n = \frac{1}{\sqrt{5}} \frac{(1+\sqrt{5})^n - (1-\sqrt{5})^n }{2^n}
    $$
5. Số  Catanla
    - Công thức:
    $$
    Catanla_n = \frac{1}{n+1}C_{2n}^n = \frac{(2n)!}{(n+1)!n!} = \frac{(n+2)(n+3)..(2n)}{1*2*..*n}
    $$
    - Bài toán:
      - Số cách xếp n ngoặc mở và n ngoặc đóng đúng đắn.
      - Số cây nhị phân khác nhau có đúng (n+1) lá.
      - Số cách chia đa giác lồi (n + 2) đỉnh thành các tam giác (n tam giác) bằng cách vẻ các đường chéo không cắt nhau trong tam giác.
6. Nhị thức Newton
    
    $$ (x + y)^n = C_n^0x^n + C_n^1x^{n-1}y +...+ C_n^{n-1}xy^{n-1} + C_n^ny^n = ∑_{k=0}^n C_n^kx^{n-k}y^k $$
7. **Chú ý**
   - Số chữ số 0 tận cùng của $n!$ :    $⌊\frac{n}{5}⌋ + ⌊\frac{n}{5^2}⌋ + ⌊\frac{n}{5^3}⌋ ...$
   - Sàng nguyên tố  **Eratosthenes**
     - Từ 1 đến $N$:  
        Độ phức tạp của thuật toán là $O(N\log{N})$.
        ````c++
        bool isPrime[N+1];
        for(int i = 0; i <= N;++i) 
            isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= N; ++i)
            if(isPrime[i] == true)
                for(int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
        ````
     - Trên đoạn $[L,R]$
        
        Độ phức tạp của thuật toán là $O(\sqrt{R}∗k)$ với k là hằng số.
        ````c++
        bool isPrime[r - l + 1]; //filled by true
        for (long long i = 2; i * i <= r; ++i) {
            for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
                isPrime[j - l] = false;
            }
        }
        for (long long i = max(l, 2); i <= r; ++i) {
            if (isPrime[i - l]) {
                //then i is prime
            }
        }
        ````
    - Đếm số lượng sâu nhị phân độ dài n mà không có 2 số 1 nào đứng cạnh nhau: Dãy Fibonanci
    - Số **hoán vị phân biệt** của sâu kí tự $s = "s_1s_2s_3..s_{n-1}s_n"$ là 
    $\frac{n!}{c_1!c_2!...c_k!}$ với $c_1, c_2...c_k$ là số lần xuất hiện của $k$ kí tự phân biệt trong chuỗi. Ví dụ, s = "aab" có $\frac{3!}{1!2!} = 3$ hoán vị là "aab", "aba", "baa"



# Sắp xếp
1. Thư viện thuật toán c++ 
   - [sort - c++](http://www.cplusplus.com/reference/algorithm/sort/) $O(N\log{N})$
   - Sắp xếp bằng cách đếm phân phối (*Distribution Counting*)
     - Bài toán: Sắp xếp mảng A gồm các số nguyên nằm trong khoảng từ 0 đến K.
     - Độ phức tạp:  $O(max(N,K)$
     - Ý tưởng: Đếm số lần xuất hiện của từng phần tử 
2. Ứng dụng sắp xếp
   - ***Tìm kiếm nhị phân***
3. Chú ý
   -    Khi $X$ là số nhỏ thứ $⌊\frac{N}{2}⌋+1$ của dãy $a_1, a_2, ..., a_n$ thì hàm 
    $
    F(X) = |a_1 - X| + |a_2 - X|+ ... + |a_n - X|
    $
    đạt giá trị nhỏ **nhất**.

#