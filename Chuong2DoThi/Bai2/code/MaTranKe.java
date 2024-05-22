import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class MaTranKe {
    public int[][] mangMaTranke;
    public int n;

    MaTranKe() {
        n = 0;
        mangMaTranke = new int[0][0];
    }

    public void inMaTran() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(mangMaTranke[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void inDanhSachCacCanh() {
        System.out.print("Danh sach cac Canh: ");
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (mangMaTranke[i][j] == 1) {
                    System.out.print("{" + i + "," + j + "} ");
                }
            }
        }
        System.out.println();
    }

    public void inBacCuaMoiDinh() {
        System.out.println("Danh sach cac Bac: ");
        for (int i = 1; i <= n; i++) {
            int bac = 0;
            for (int j = 1; j <= n; j++) {
                if (mangMaTranke[i][j] == 1) {
                    bac++;
                }
            }
            System.out.println("deg(" + i + ")=" + bac);
        }
    }

    public void docFile(String fileName) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line;
            int i = 1;
            line = reader.readLine(); // lấy ra dòng đầu tiên
            n = Integer.parseInt(line); // lưu dòng đầu tiên vào n
            mangMaTranke = new int[n + 1][n + 1]; // cấp phát bộ nhớ cho mảng, tăng kích thước lên 1

            while ((line = reader.readLine()) != null) { // lấy ra các dòng tiếp theo
                String[] tokens = line.split(" "); // lưu vào chuỗi và loại bỏ khoảng trắng
                for (int j = 1; j <= n; j++) {
                    mangMaTranke[i][j] = Integer.parseInt(tokens[j - 1]);
                }
                i++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        MaTranKe maTranKe = new MaTranKe();
        maTranKe.docFile("maTranKe.txt"); // Truyền tên tập tin với phần mở rộng
        maTranKe.inMaTran();
        maTranKe.inDanhSachCacCanh();
        maTranKe.inBacCuaMoiDinh();

    }
}
