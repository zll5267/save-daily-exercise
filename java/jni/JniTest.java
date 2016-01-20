
class JniTest
{
    public static native void native_helloworld();
    public static void main(String[] args)
    {
        System.loadLibrary("JniTest");
        System.out.println("Hello World");
        native_helloworld();
    }
}
