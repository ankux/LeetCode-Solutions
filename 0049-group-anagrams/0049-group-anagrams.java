class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<>();

        for(String str : strs) {
            //pre-store the untampered val
            String val = str;
            
            //convert to char array
            char[] charArr = str.toCharArray();

            //now sort the array
            Arrays.sort(charArr);

            //convert back to string
            String key = new String(charArr);

            //check if the key doesn't exist
            if(!mp.containsKey(key)) {
                mp.put(key, new ArrayList<>());
            }

            //add it to the map
            mp.get(key).add(val);
        }

        List<List<String>> ans = new ArrayList<>();

        // we can also do: return new ArrayList<>(mp.values());
        
        for(String key : mp.keySet()) {
            ans.add(mp.get(key));
        }

        return ans;
    }
}