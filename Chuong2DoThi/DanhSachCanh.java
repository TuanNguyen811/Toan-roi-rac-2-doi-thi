import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class danhSach {
    int dau;
    int cuoi;

    danhSach(int dau, int cuoi) {
        this.dau = dau;
        this.cuoi = cuoi;
    }
}

public class DanhSachCanh {
    danhSach[] danhSachCanh;
    int n, m; // n số đỉnh, m số cạnh

    DanhSachCanh() {
        danhSachCanh = new danhSach[0];
        n = 0;
        m = 0;
    }

    public void inDanhSachCanh() {
        System.out.println("Danh sach canh: n= " + n + ", m= " + m);
        for (int i = 1; i < m; i++) {
            System.out.println(danhSachCanh[i].dau + " " + danhSachCanh[i].cuoi);
        }
    }

    public void bacCuaDinh() {
        System.out.println("Danh sach bac: ");
        for (int i = 1; i <= n; i++) {
            int bac = 0;
            for (int j = 1; j <= m; j++) {
                if (danhSachCanh[j].dau == i || danhSachCanh[j].cuoi == i) {
                    bac++;
                }
            }
            System.out.println("Deg(" + i + ")=" + bac);
        }
    }

    public void docFile(String fileName) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line;
            line = reader.readLine();// Lấy ra dòng đầu tiên
            String[] line1 = line.split(" ");// tách ra thành 2, loại bỏ khoảng trắng
            n = Integer.parseInt(line1[0]);
            m = Integer.parseInt(line1[1]);// gan gia tri
            danhSachCanh = new danhSach[m + 1];// cap phat bo nho cho mang
            int i = 1;
            while ((line = reader.readLine()) != null) {
                String[] lines = line.split(" ");// tach dong ra
                danhSachCanh[i] = new danhSach(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]));
                i++;
            }

            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        DanhSachCanh danhSachCanh = new DanhSachCanh();

        danhSachCanh.docFile("danhSachCanh.txt");
        danhSachCanh.inDanhSachCanh();
        danhSachCanh.bacCuaDinh();
    }
}
