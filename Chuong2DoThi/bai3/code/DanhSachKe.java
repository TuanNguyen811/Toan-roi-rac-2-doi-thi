package code;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class DanhSachKe {
    List<Integer> danhSach;
    int[] head;
    int n;

    DanhSachKe() {
        danhSach = new ArrayList<>();
        n = 0;
    }

    // đọc file danh sách kề
    public void docFile(String fileName) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line = reader.readLine();
            n = Integer.parseInt(line);
            head = new int[n + 2];
            head[1] = 0;
            danhSach.add(null);
            int i = 2;
            while ((line = reader.readLine()) != null) {
                String[] lines = line.split(" ");
                head[i] = Integer.parseInt(lines[0]);
                i++;
                for (int j = 1; j < lines.length; j++) {
                    danhSach.add(Integer.parseInt(lines[j]));
                }
            }
            head[n + 1] = head[n];
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void indanhSach() {
        System.out.println("Danh sach dinh ke: ");
        for (int i = 1; i <= n + 1; i++) {
            System.out.print(head[i] + " ");
        }
        System.out.println();
        for (int i = 1; i < danhSach.size(); i++) {
            System.out.print(danhSach.get(i) + " ");
        }
    }

    public void inMaTranKe() {
        // tạo ma trận rỗng
        int[][] maTranKe = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maTranKe[i][j] = 0;
            }
        }
        // gán giá trị từ head cho ma trận kề
        for (int i = 0; i < n; i++) {
            for (int j = head[i + 1] + 1; j <= head[i + 2]; j++) {
                maTranKe[i][danhSach.get(j) - 1] = 1;
            }
        }
        // in ma trận
        System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(maTranKe[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void bacCuaDinhKe() {
        System.out.println("Danh sach bac cua dinh: ");
        for (int i = 1; i <= n; i++) {
            System.out.println("deg-(" + i + ")=" + (head[i + 1] - head[i]));
        }
        for (int i = 1; i <= n; i++) {
            int bac = 0;
            for (int j = 1; j < danhSach.size(); j++) {
                if (danhSach.get(j) == i) {
                    bac++;
                }
            }
            System.out.println("deg+(" + i + ")=" + bac);
        }

    }

    public static void main(String[] args) {
        DanhSachKe danhSachKe = new DanhSachKe();
        danhSachKe.docFile("danhSachKe2.txt");
        danhSachKe.inMaTranKe();
        danhSachKe.bacCuaDinhKe();
    }
}
