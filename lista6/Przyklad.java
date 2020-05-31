
class Przyklad {
    public static void main(String[] args) {
        int[] a={9,5,3,1,0,-1,11,6,32,14,-23,17,98};
        MergeSort m = new MergeSort(a);
        Thread ms = new Thread(m);
        ms.start();
        try {
            ms.join();
        } catch (Exception e) {}
        
        for(int i=0; i<a.length; i++) {
            System.out.print(a[i]+" ");
        }
    }
}