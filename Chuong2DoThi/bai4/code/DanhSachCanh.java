import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class danhSach {
    int dau;
    int cuoi;
    int trongSo;

    danhSach(int dau, int cuoi, int trongSo) {
        this.dau = dau;
        this.cuoi = cuoi;
        this.trongSo = trongSo;
    }
}
public class DanhSachCanh {
    danhSach[] danhSachCanh;
    int n, m; // n số đỉnh, m số cạnh
    int[][] maTranKe;   
    DanhSachCanh() {
        danhSachCanh = new danhSach[0];
        n = 0;
        m = 0;
    }

    public void inDanhSachCanh() {
        System.out.println("Danh sach canh: n= " + n + ", m= " + m);
        for (int i = 1; i <= m; i++) {
            System.out.println(danhSachCanh[i].dau + " " + danhSachCanh[i].cuoi + " " + danhSachCanh[i].trongSo);
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
                danhSachCanh[i] = new danhSach(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]),
                        Integer.parseInt(lines[2]));
                i++;
            }
            
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void inMaTranKe() {
        int[][] maTranKe = new int[n + 1][n + 1];
        System.out.println("Ma tran ke: ");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                maTranKe[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            maTranKe[danhSachCanh[i].dau][danhSachCanh[i].cuoi] = danhSachCanh[i].trongSo;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(maTranKe[i][j] + " ");
            }
            System.out.println();
        }
    }
    public void tongBanBacChanLe(){
        
    }
    public static void main(String[] args) {
        DanhSachCanh danhSachCanh = new DanhSachCanh();
        danhSachCanh.docFile("danhSachCanh.txt");
        danhSachCanh.inDanhSachCanh();
        danhSachCanh.inMaTranKe();
    }

}
