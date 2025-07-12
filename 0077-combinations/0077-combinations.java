class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public void solve(int i, int limit, int k, List<Integer> temp, List<Integer> arr) {
        if(limit == k) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        if (i == arr.size()) return;

        temp.add(arr.get(i));
        solve(i+1, limit+1, k, temp, arr);
        temp.remove(temp.size() - 1);

        solve(i+1, limit, k, temp, arr);
    }

    public List<List<Integer>> combine(int n, int k) {
        List<Integer> arr = new ArrayList<>();
        for(int i=1; i<=n; i++) {
            arr.add(i);
        }

        List<Integer> temp = new ArrayList<>();

        solve(0, 0, k, temp, arr);

        return ans;
    }
}