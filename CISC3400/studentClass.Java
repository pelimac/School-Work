/*Brandon McFarlane
  CISC 3400
 */

public class studentClass{
        
    // Create static fields classNumber, className, instructor
    private static int classNumber = 3400;
    private static String className = "CISC3400";
    private static String instructor = "Dr. S";

    
    //Create instance fields studentId, firstName, lastName, address, city, state, email, etc.
    // Make all fields private 
    private String firstName;
    private String lastName;
    private String address;
    private String city;
    private String state;
    private String email;
    private int studentId;

    //Create a constructor for the class that takes student firstName and lastName Constructor should generate a sequential student id
    //(ids should start with 1000 and increment for each new student)
    //Create a second constructor that takes all fields (firstName, lastName, address, city, state, email, etc.)

    public studentClass(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.studentId = 1000 + studentClass.getClassNumber();
        studentClass.setClassNumber(studentClass.getClassNumber() + 1);
    }
    
    //Create a second constructor that takes all fields (firstName, lastName, address, city, state, email, etc.)
    //Constructor should call the first constructor to initialize firstname and lastname,
    //Constructor should initialize the rest of the fields.

    public studentClass(String firstName, String lastName, String address, String city, String state, String email) {
        this(firstName, lastName);
        this.address = address;
        this.city = city;
        this.state = state;
        this.email = email;
    }

    //Create getter and setter methods for the static fields
    public int getClassNumber(){
        return classNumber;
    }
    public void setClassNumber(int classNumber){
        this.classNumber = classNumber;
    }
    public String getClassName(){
        return className;
    }
    public void setClassName(String className){
        this.className = className;
    }
    public String getInstructor(){
        return instructor;
    }
    public void setInstructor(String instructor){
        this.instructor = instructor;
    }

    //Create getter and setter methods for the instance fields
    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getStudentId() {
        return studentId;
    }

    public String toString() {
        return "Student{" +
                "classNumber=" + classNumber +
                ", className='" + className + '\'' +
                ", instructor='" + instructor + '\'' +
                ", studentId=" + studentId +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", address='" + address + '\'' +
                ", city='" + city + '\'' +
                ", state='" + state + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
