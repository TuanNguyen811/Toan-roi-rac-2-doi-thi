import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DanhSachKe {
    int[] danhSach;
    int n;
    int[] head;
    int nHend;

    DanhSachKe() {
        danhSach = new int[0];
        head = new int[0];
    }

    public void docFile(String fileName) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String[] line1 = reader.readLine().split(" ");
            String[] line2 = reader.readLine().split(" ");
            n = line2.length;
            nHend = line1.length;
            danhSach = new int[n + 1];
            head = new int[nHend + 1];
            for (int i = 1; i <= n; i++) {
                danhSach[i] = Integer.parseInt(line2[i - 1]);
            }
            for (int i = 1; i <= nHend; i++) {
                head[i] = Integer.parseInt(line1[i - 1]);
            }
            // Chỉ định nơi kết thúc của mỗi danh sách kề
            head[nHend] = n;
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void indanhSach() {
        System.out.println("Danh sach dinh ke: ");
        for (int i = 1; i < nHend; i++) {
            System.out.print(i + "={ ");
            for (int j = head[i] + 1; j <= head[i + 1]; j++) {
                System.out.print(danhSach[j] + ",");
            }
            System.out.println("}");
        }
    }

    public void inHaimang() {
        for (int i = 1; i <= nHend; i++) {
            System.out.print(head[i] + "  ");
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            System.out.print(danhSach[i] + "  ");
        }
        System.out.println();
    }

    public void bacCuaDinhKe() {
        System.out.println("Danh sach bac cua dinh: ");
        for (int i = 1; i <= nHend; i++) {
            System.out.println("deg(" + i + ")=" + (head[i + 1] - head[i]));
        }
    }

    public static void main(String[] args) {
        DanhSachKe danhSachKe = new DanhSachKe();
        danhSachKe.docFile("danhSachKe.txt");
        danhSachKe.inHaimang();
        danhSachKe.indanhSach();
        danhSachKe.bacCuaDinhKe();
    }
}
