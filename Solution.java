class Solution{
    public static int lengthoflastword(String s){
        s = s.trim();
        int i =s.indexOf(' ');
        s.lastIndexOf(i);
        if(i>0){
            return s.substring(i).length(); 
        }
        return s.length();
    }
    public static void main(String args[]){
        lengthoflastword("a Hello World     ");
    }
}