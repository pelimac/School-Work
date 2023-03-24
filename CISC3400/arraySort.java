/*Brandon McFarlane
  CISC 3400
 */

public class arraySort {
    public static void main(String[] args) 
    {
        // Check if at least 3 words were entered
        if (args.length < 3) 
        {
            System.out.println("Please enter at least 3 words as command line arguments");
            return;
        }
        
        // Print all entered words on separate lines
        // The for loop is iterating over the elements of the args array, assigning each element in turn to the word variable
        for (String word : args) 
        {
            System.out.println(word);
        }
        
        // Concatenate words into a single string with a space between them
        String concatenatedWords = String.join(" ", args);
        System.out.println(concatenatedWords);
        
        // Sort words array in ascending order
        sortArray(args, 0, args.length - 1); // Array of strings, 0, which is the index of the first element in the array, and args.length - 1, which is the index of the last element in the array
        
        // Print sorted words using StringBuilder
        StringBuilder sortedWords = new StringBuilder();// Creates a new StringBuilder object called sortedWords
        for (String word : args) 
        {
            sortedWords.append(word).append("\n");// Each word from the sorted args array is appended followed by a newline character
        }
        System.out.println(sortedWords);
        
        // Concatenate sorted words into a single StringBuilder with a space between them
        StringBuilder concatenatedSortedWords = new StringBuilder(); // Loops through the args array and for each element in the array
        for (String word : args) 
        {
            concatenatedSortedWords.append(word).append(" "); // Appends the element followed by a space to the concatenatedSortedWords StringBuilder object
        }
        System.out.println(concatenatedSortedWords);
    }
    
    // Recursive implementation of quicksort algorithm to sort words array in ascending order
    private static void sortArray(String[] arr, int low, int high) 
    {
        if (low < high) 
        {
            // partition index
            int partitionIndex = partition(arr, low, high);
            
            // sort left sub-array
            sortArray(arr, low, partitionIndex - 1);
            
            // sort right sub-array
            sortArray(arr, partitionIndex + 1, high);
        }
    }
    
    // Partition method for quicksort algorithm
    private static int partition(String[] arr, int low, int high) 
    {
        // choose rightmost element as pivot
        String pivot = arr[high];
        
        // index of smaller element
        int i = low - 1;
        
        for (int j = low; j < high; j++) // Loops through the sub-array between the "low" and "high" indexes and checks if each element is smaller than or equal to the pivot element.


        {
            // if current element is smaller than or equal to pivot
            if (arr[j].compareToIgnoreCase(pivot) <= 0) // Compares the current element with the pivot element ignoring the case of the letters. If the current element is smaller than or equal to the pivot element, the block of code inside the if statement is executed.
            {
                i++;
                
                // swap arr[i] and arr[j]
                String temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // swap arr[i+1] and arr[high] (or pivot)
        String temp = arr[i + 1]; // A temporary variable temp is declared to store the value of the element that comes after the last smaller element.
        arr[i + 1] = arr[high]; // The element that comes after the last smaller element is assigned the value of the pivot element, which is located at the high index.
        arr[high] = temp; // The pivot element is assigned the value stored in temp, which is the value of the element that comes after the last smaller element.
        
        return i + 1; // The new index of the pivot element is returned. It is the index of the element that comes after the last smaller element.
    }
}
