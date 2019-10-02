/*this is one of my favorite script because it is linked with OOP and i love it.*/
public class pet{

    
    String name; 
    String breed; 
    int age; 
    String color; 

    
    public pet(String name, String breed, int age, String color){
    
        this.name = name; 
        this.breed = breed; 
        this.age = age; 
        this.color = color; 
    } 

    // method 1 
    public String getName() {
    
        return name; 
    } 

     
    public String getBreed() {
    
        return breed; 
    } 

    
    public int getAge() 
    { 
        return age; 
    } 

    
    public String getColor() 
    { 
        return color; 
    } 

    @Override
    public String toString() 
    { 
        return("Hi my name is "+ this.getName()+ 
            ".\nMy breed,age and color are " + 
            this.getBreed()+"," + this.getAge()+ 
            ","+ this.getColor()); 
    } 

    public static void main(String[] args) 
    { 
        pet ronnie = new pet("ronnie","germanShepherd", 6, "brown"); 
        System.out.println(ronnie.toString()); 
    } 
} 
