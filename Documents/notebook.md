## Kiến thức cơ bản
1. Số nguyên tố.
   - Nếu p là số nguyên tố và a là số tự nhiên *thì* 
    $$ 
    a^p \mod p = a 
    $$
2. Ước số, bội số. 
  
    2.1 N được phân tích thành thừa số nguyên tố như sau:
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