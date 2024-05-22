import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class thuatToanToMau {
    int[][] maTranKe;
    int n;
    int[] danhSachMau;

    class DanhSachDinh {
        int dinh;
        int bac;

        DanhSachDinh() {
            dinh = 0;
            bac = 0;
        }
    }

    thuatToanToMau() {
        n = 0;
    }

    void docFile(String tenFile) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(tenFile));
            n = Integer.parseInt(reader.readLine());
            maTranKe = new int[n][n];
            String line;
            int i = 0;
            while ((line = reader.readLine()) != null) {
                String[] lines = line.split(" ");
                for (int j = 0; j < n; j++) {
                    maTranKe[i][j] = Integer.parseInt(lines[j]);
                }
                i++;
            }
            reader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void thuatToan() {
        danhSachMau = new int[n];
        DanhSachDinh[] danhSachDinh = new DanhSachDinh[n];
        for (int i = 0; i < n; i++) {
            danhSachMau[i] = -1;
            danhSachDinh[i] = new DanhSachDinh();
            danhSachDinh[i].dinh = i;
            int bac = 0;
            for (int j = 0; j < n; j++) {
                if (maTranKe[i][j] == 1) {
                    bac++;
                }
            }
            danhSachDinh[i].bac = bac;
        }

        // Sắp xếp danh sách đỉnh theo số bậc giảm dần
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (danhSachDinh[i].bac < danhSachDinh[j].bac) {
                    DanhSachDinh temp = danhSachDinh[i];
                    danhSachDinh[i] = danhSachDinh[j];
                    danhSachDinh[j] = temp;
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        // System.out.println(danhSachDinh[i].dinh + 1 + "" + danhSachDinh[i].bac);
        // }

        int m = 0; // màu bắt đầu
        int soLuong = 0; // số lượng đỉnh chưa được tô màu
        while (soLuong < n) {
            int i = 0;
            if (danhSachMau[danhSachDinh[i].dinh] == -1) {
                m++;
                danhSachMau[danhSachDinh[i].dinh] = m;
                soLuong++;
                for (int j = 0; j < n; j++) {
                    if (maTranKe[danhSachDinh[i].dinh][j] == 0) {
                        danhSachMau[danhSachDinh[j].dinh] = m;
                        soLuong++;
                    }
                }
            } else {
                i++;
            }
        }

        // In kết quả
        System.out.println("Dinh/Mau");
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + danhSachMau[i]);
        }
    }

    void thuatToan2() {
        danhSachMau = new int[n];
        DanhSachDinh[] danhSachDinh = new DanhSachDinh[n];
        for (int i = 0; i < n; i++) {
            danhSachMau[i] = -1;
            danhSachDinh[i] = new DanhSachDinh();
            danhSachDinh[i].dinh = i;
            int bac = 0;
            for (int j = 0; j < n; j++) {
                if (maTranKe[i][j] == 1) {
                    bac++;
                }
            }
            danhSachDinh[i].bac = bac;
        }

        // Sắp xếp danh sách đỉnh theo số bậc giảm dần
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (danhSachDinh[i].bac < danhSachDinh[j].bac) {
                    DanhSachDinh temp = danhSachDinh[i];
                    danhSachDinh[i] = danhSachDinh[j];
                    danhSachDinh[j] = temp;
                }
            }
        }

        int m = 0; // màu bắt đầu
        int soLuong = 0; // số lượng đỉnh chưa được tô màu
        int i = 0;
        while (soLuong < n && i < n) {
            // kiểm tra xem đỉnh đã được tôi màu chưa
            if (danhSachMau[danhSachDinh[i].dinh] == -1) {
                m++;
                danhSachMau[danhSachDinh[i].dinh] = m;
                soLuong++;
                for (int j = 0; j < n; j++) {
                    if (maTranKe[danhSachDinh[i].dinh][j] == 0 && danhSachMau[j] == -1) { // chỉ tô màu đỉnh chưa được
                                                                                          // tô màu và không kề với đỉnh
                        // đã tô màu
                        danhSachMau[j] = m;
                        soLuong++;
                    }
                }
            }
            i++;
        }

        // In kết quả
        System.out.println("Dinh/Mau");
        for (i = 0; i < n; i++) {
            System.out.println(i + 1 + " " + danhSachMau[i]);
        }
    }

    public static void main(String[] args) {
        thuatToanToMau tt = new thuatToanToMau();
        tt.docFile("maTran.txt");
        tt.thuatToan2();
    }
}