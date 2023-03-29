import java.util.ArrayList;

public class TestStudent {
    public static void main(String[] args) {
        // Create an instance of studentClass
        studentClass.setClassNumber(101);
        studentClass.setClassName("Computer Science");
        studentClass.setInstructor("John Smith");

        studentClass s1 = new studentClass("Alice", "Smith");
        studentClass s2 = new studentClass("Bob", "Johnson", "123 Main St", "Anytown", "CA", "bjohnson@example.com");
        studentClass s3 = new studentClass("Charlie", "Brown");
        s3.setAddress("456 Elm St");
        s3.setCity("Smallville");
        s3.setState("NY");
        s3.setEmail("cbrown@example.com");
        studentClass s4 = new studentClass("Dave", "Davis", "789 Oak St", "Bigtown", "IL", "ddavis@example.com");
        studentClass s5 = new studentClass("Eve", "Evans");

        // Print out the student information
        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.println(s3.toString());
        System.out.println(s4.toString());
        System.out.println(s5.toString());

        // Modify some student information
        s1.setInstructor("Jane Doe");
        s2.setAddress("456 Main St");
        s3.setFirstName("Charles");
        s4.setEmail("ddavis2@example.com");
        s5.setLastName("Johnson");

        // Print out the modified student information
        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.println(s3.toString());
        System.out.println(s4.toString());
        System.out.println(s5.toString());
    }
}
