package com.mk.test;

/**
 * Hello world!
 *
 */
public class App
{
	private int value;
	private App next;
	
    public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

	public App getNext() {
		return next;
	}

	public void setNext(App next) {
		this.next = next;
	}

	public static void main( String[] args )
    {
		App first = new App();
		first.setValue(0);
		first.setNext(null);
		App last = first;
		for( int i = 1; i < 10; i++){
			App app = new App();
			app.setValue(i);
			last.setNext(app);
			last = app;
		}
		App current = first;
		while(current != null){
			System.out.print(current.getValue() + " ");
			current = current.getNext();
		}
		System.out.println("\n after convert:");
		first.convertList(first);
		current = last;
		while(current != null){
			System.out.print(current.getValue() + " ");
			current = current.getNext();
		}
		System.out.println();
        System.out.println( "Hello World!" );
        System.out.println( "Hello You!" );
    }
	
	public App convertList(App first){
		App app = null;
		if(first.getNext() != null){
			app = convertList(first.getNext());
			app.setNext(first);
			first.setNext(null);
		}
		return first;
	}
	
	public void print(){
		System.out.println("Hello World!");
	}
}