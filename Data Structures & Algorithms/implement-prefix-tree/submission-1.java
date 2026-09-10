class TrieNode{
    List<TrieNode> child;
    boolean isEnd;
    TrieNode(){
        isEnd = false;
        child = new ArrayList<>(Collections.nCopies(26, null));
    }
}
class PrefixTree {
    TrieNode root;
    public PrefixTree() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode temp = root;
        for(int i = 0;i<word.length();i++){
            char ch = word.charAt(i);
            if(temp.child.get(ch-'a') == null){
                temp.child.set(ch-'a', new TrieNode());
            }
            temp = temp.child.get(ch-'a');
        }
        temp.isEnd = true;
    }

    public boolean search(String word) {
        TrieNode temp = root;
        for(int i = 0;i<word.length();i++){
            char ch = word.charAt(i);
            if(temp.child.get(ch-'a') == null){
                return false;
            }
            temp = temp.child.get(ch-'a');
        }
        return temp.isEnd;
    }

    public boolean startsWith(String prefix) {
    TrieNode temp = root;
        for(int i = 0;i<prefix.length();i++){
            char ch = prefix.charAt(i);
            if(temp.child.get(ch-'a') == null){
                return false;
            }
            temp = temp.child.get(ch-'a');
        }
        return true;
    }
}
