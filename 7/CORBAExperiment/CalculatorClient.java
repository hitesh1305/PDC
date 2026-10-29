import CalculatorApp.*;
import org.omg.CosNaming.*;
import org.omg.CORBA.*;

public class CalculatorClient {
    public static void main(String[] args) {
        try {
            ORB orb = ORB.init(args, null);

            org.omg.CORBA.Object obj =
                orb.resolve_initial_references("NameService");

            NamingContextExt nc =
                NamingContextExtHelper.narrow(obj);

            Calculator c =
                CalculatorHelper.narrow(nc.resolve_str("Calculator"));

            int a = 20, b = 10;

            System.out.println("Addition = " + c.add(a, b));
            System.out.println("Subtraction = " + c.subtract(a, b));
            System.out.println("Multiplication = " + c.multiply(a, b));
            System.out.println("Division = " + c.divide(a, b));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}