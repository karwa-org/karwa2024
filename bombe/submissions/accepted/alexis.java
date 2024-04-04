import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class alexis {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static final long MOD = (1L << 40);
    static final long A = 911382323;

    static long safeMod(long a, long m) {
        return (a % m + m) % m;
    }

    static void solve() {
        FastReader scanner = new FastReader();

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        char[][] a = new char[n][m];

        for (int i = 0; i < n; i++) {
            String row = scanner.next();
            for (int j = 0; j < m; j++) {
                a[i][j] = row.charAt(j);
            }
        }

        long[] pre = new long[m];
        pre[0] = 1;

        for (int i = 1; i < m; i++) {
            pre[i] = safeMod(pre[i - 1] * A, MOD);
        }

        long[] hs = new long[n];
        Map<Long, Pair<Long, Long>> cnt = new HashMap<>();

        for (int i = 0; i < n; i++) {
            long hash = 0;

            for (int j = 0; j < m; j++) {
                hash += a[i][j] * pre[j];
                hash = safeMod(hash, MOD);
            }
            hs[i] = hash;

            cnt.put(hs[i], new Pair<>(i + 1L, 0L));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hs[i] -= (a[i][m - j - 1] * pre[m - 1]) % MOD;
                hs[i] %= MOD;
                hs[i] *= A;
                hs[i] %= MOD;
                hs[i] += a[i][m - j - 1];
                hs[i] %= MOD;

                if(cnt.get(hs[i]) == null) {
                    cnt.put(hs[i], new Pair<>(0L, 0L));
                }
                Pair<Long, Long> pair = cnt.get(hs[i]);

                if (pair.first == 0L) {
                    pair.first = i + 1L;
                } else if (pair.second == 0L && pair.first != (i + 1L)) {
                    pair.second = i + 1L;
                } else if (pair.first > i + 1L) {
                    pair.first = i + 1L;
                } else if (pair.second > i + 1L) {
                    pair.second = i + 1L;
                }

                cnt.replace(hs[i], pair);

            }
        }

        Pair<Long, Long> mini = new Pair<>(10_000_000_000L, 10_000_000_000L);

        for (Map.Entry<Long, Pair<Long, Long>> entry : cnt.entrySet()) {
            Pair<Long, Long> value = entry.getValue();

            if (value.first == 0 || value.second == 0) continue;
            if (value.compareTo(mini) < 0) mini = value;
        }

        if (mini.first == 10_000_000_000L && mini.second == 10_000_000_000L) {
            System.out.println("BOOM!");
        } else {
            System.out.println(mini.first + " " + mini.second);
        }
    }

    public static void main(String[] args) {
        solve();
    }

    static class Pair<T extends Comparable<T>, U extends Comparable<U>> implements Comparable<Pair<T, U>> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair<T, U> other) {
            int cmp = this.first.compareTo(other.first);
            if (cmp != 0) {
                return cmp;
            }
            return this.second.compareTo(other.second);
        }
    }
}
