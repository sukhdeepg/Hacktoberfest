#This program is my favourite because it almost uses all the aspects of basics of Java!

class StringRotation {
static boolean areRotations(String str1, String str2) {
return (str1.length() == str2.length()) &&
((str1 + str1).indexOf(str2) != -1);
}
public static void main (String[] args) {
System.out.println(“Name: Pranit Brahmbhatt”);
System.out.println(“Enrollment Number: 170410107010”);
String str1 = "tip";
String str2 = "pit";
if (areRotations(str1, str2))
System.out.println("Strings are rotations of each other");
else
System.out.printf("Strings are not rotations of each other");
}
}