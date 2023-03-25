/*Brandon McFarlane
  CISC 3400
 */
public class DistanceConversion
{
  public static void main(String[] args) 
  {
    // initialize variables for 1 mile and 0.5 miles
    double mile = 1.0;
    double halfMile = 0.5;

    // calculate yards for 1 mile and 0.5 miles
    double yard = mile * 1760;
    double halfYard = halfMile * 1760;

    // calculate feet for 1 mile and 0.5 miles
    double foot = mile * 5280;
    double halfFoot = halfMile * 5280;

    // calculate inches for 1 mile and 0.5 miles
    double inch = mile * 63360;
    double halfInch = halfMile * 63360;

    // calculate kilometers for 1 mile and 0.5 miles
    double kilometer = mile * 1.609344;
    double halfKilometer = halfMile * 1.609344;

    // calculate meters for 1 mile and 0.5 miles
    double meter = mile * 1609.344;
    double halfMeter = halfMile * 1609.344;

    // calculate centimeters for 1 mile and 0.5 miles
    double centimeter = mile * 160934.4;
    double halfCentimeter = halfMile * 160934.4;

    // calculate millimeters for 1 mile and 0.5 miles
    double millimeter = mile * 1609344;
    double halfMillimeter = halfMile * 1609344;

    //volume conversion
    double gallon = 1.0;
    double halfGallon = 0.5;

    double quart = gallon * 4;
    double halfQuart = halfGallon * 4;

    double pint = gallon * 8;
    double halfPint = halfGallon * 8;

    double ounce = gallon * 128;
    double halfOunce = halfGallon * 128;

    double liter = gallon * 3.7854118;
    double halfLiter = halfGallon * 3.7854118;

    double milliliter = gallon * 3785.4118;
    double halfMilliliter = halfGallon * 3785.4118;

    // print the conversion table
    System.out.println("1 mile is equal to 0.5 miles");
    System.out.println("---------------------- ---------");
    System.out.println("Miles:       " + mile + " " + halfMile);
    System.out.println("Yards:       " + yard + " " + halfYard);
    System.out.println("Feet:        " + foot + " " + halfFoot);
    System.out.println("Inches:      " + inch + " " + halfInch);
    System.out.println("Kilometer:   " + kilometer + " " + halfKilometer);
    System.out.println("Meter:       " + meter + " " + halfMeter);
    System.out.println("Centimeter:  " + centimeter + " " + halfCentimeter);
    System.out.println("Milimeter:   " + millimeter + " " + halfMillimeter);
    System.out.println("\n1 gallon is equal to 0.5 gallons");
    System.out.println("--------------------- -----------");
    System.out.println("Gallons:     " + gallon + " " + halfGallon);
    System.out.println("Quarts:      " + quart + " " + halfQuart);
    System.out.println("Pints:       " + pint + " " + halfPint);
    System.out.println("Ounces:      " + ounce + " " + halfOunce);
    System.out.println("Liter:       " + liter + " " + halfLiter);
    System.out.println("Milliliter:  " + milliliter + " " + halfMilliliter);
  }
}
