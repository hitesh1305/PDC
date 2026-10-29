
import CalculatorApp.*;
import org.omg.CosNaming.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class CalculatorServer {
    public static void main(String[] args) {
        try {
            ORB orb = ORB.init(args, null);

            POA rootpoa = POAHelper.narrow(
                orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();

            CalculatorImpl impl = new CalculatorImpl();

            org.omg.CORBA.Object ref =
                rootpoa.servant_to_reference(impl);

            Calculator href = CalculatorHelper.narrow(ref);

            org.omg.CORBA.Object obj =
                orb.resolve_initial_references("NameService");

            NamingContextExt nc =
                NamingContextExtHelper.narrow(obj);

            nc.rebind(nc.to_name("Calculator"), href);

            System.out.println("Calculator Server Ready...");
            orb.run();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
