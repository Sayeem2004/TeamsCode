import java.util.*;
import java.io.*;

public class Main {
    static class Reader {
    final private int BUF = 1 << 16;
    private DataInputStream d;
    private byte[] bu;
    private int bufP, by;
    public Reader() {
      d = new DataInputStream(System.in);
      bu = new byte[BUF];
      bufP = by = 0;
    }
    public Reader(String fl) throws IOException {
      d = new DataInputStream(new FileInputStream(fl));
      bu = new byte[BUF];
      bufP = by = 0;
    }
    public String readLine() throws IOException {
      byte[] b = new byte[1024];
      int ct = 0, c;
      while ((c = read()) != -1) {
        if (c == '\n') break;
          b[ct++] = (byte) c;
 }
      return new String(b, 0, ct);
    }
    public int nextInt() throws IOException {
      int r = 0;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (n) return -r;
      return r;
    }
    public long nextLong() throws IOException {
      long r = 0;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (n) return -r;
      return r;
    }
    public double nextDouble() throws IOException {
      double r = 0, d = 1;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (c == '.') {
        while ((c = read()) >= '0' && c <= '9') {
          r += (c - '0') / (d *= 10);
        }
      }
      if (n) return -r;
      return r;
    }
    private void fB() throws IOException {
      by = d.read(bu, bufP = 0, BUF);
      if (by == -1) bu[0] = -1;
    }
    private byte read() throws IOException {
      if (bufP == by) fB();
      return bu[bufP++];
    }
    public void close() throws IOException {
      if (d == null) return;
      d.close();
    }
  }
  static class Writer {
    StringBuilder sb;
    public Writer() {
      sb = new StringBuilder();
    }
    public void println(String s) {
      sb.append(s).append("\n");
    }
    public void print(String s) {
      sb.append(s);
    }
    public void close() {
      if (sb == null) return;
      System.out.println(sb);
    }
  }
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        Writer w = new Writer();
        int t = r.nextInt();
        for (int q = 0; q < t; q++) {
            int N = r.nextInt();
            int K = r.nextInt();
            int max = 0;
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = r.nextInt();
                max = Math.max(max, arr[i]);
            }
            int maxB = K * max;
            if (max == 1) {
                w.println(Integer.toString(maxB));
            } else {
                w.println(Integer.toString(maxB-1));
            }
        }
        r.close();
        w.close();
    }
}
