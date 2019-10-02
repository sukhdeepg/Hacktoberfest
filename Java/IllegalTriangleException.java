import java.lang.*;

public class IllegalTriangleException extends Exception{
	
	public IllegalTriangleException() {
		super("Invalid Sides");
	}
	
	public String toString() {
		return "Triangle Sides are invalid";
	}
}
