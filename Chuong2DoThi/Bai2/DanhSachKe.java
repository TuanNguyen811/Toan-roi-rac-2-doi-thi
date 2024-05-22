import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class DanhSachKe {
    public int[][] maTranke;
    public int n;

    DanhSachKe() {
        n = 0;
        maTranke = new int[n][n];
    }

    public void xuatMang() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(maTranke[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void ghiFile() {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("maTranKe.txt"));
            writer.write(String.valueOf(n)); // Chuyển đổi n thành chuỗi trước khi ghi vào tập tin
            writer.newLine();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    writer.write(maTranke[i][j] + " ");
                }
                writer.newLine();
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void docFile() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("maTranKe.txt"));
            String line;
            int i = 0;

            line = reader.readLine();// lay ra dong dau tien
            n = Integer.parseInt(line);// luu dong dau tien vao n
            maTranke = new int[n][n]; // Tạo mảng maTranke với kích thước n x n

            while ((line = reader.readLine()) != null) {// lay ra cac dong tiep theo
                String[] tokens = line.split(" "); // luu vao string va loai bo khong trong
                for (int j = 0; j < n; j++) {
                    maTranke[i][j] = Integer.parseInt(tokens[j]);
                }
                i++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello");
        DanhSachKe danhSachKe = new DanhSachKe();
        danhSachKe.docFile();
        danhSachKe.xuatMang();
    }
}
