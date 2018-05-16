import java.util.Scanner;
import java.io.*;
import java.security.*;
import java.security.spec.X509EncodedKeySpec;

public class VerifySignature {

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String fileName,publicKeyFileName,signatureFileName;
        System.out.println("Enter file name to make signature of :");
        fileName = scan.next();
        System.out.println("Public Key File name :");
        publicKeyFileName = scan.next();
        System.out.println("Signature File name :");
        signatureFileName = scan.next();
        try {
            FileInputStream keyFile = new FileInputStream(publicKeyFileName);
            byte[] senderPublicKey = new byte[keyFile.available()];
            keyFile.read(senderPublicKey);
            X509EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(senderPublicKey);
            KeyFactory keyFactory = KeyFactory.getInstance("DSA", "SUN");
            PublicKey publicKey = keyFactory.generatePublic(publicKeySpec);

            FileInputStream signatureFile = new FileInputStream(signatureFileName);
            byte[] signatureData = new byte[signatureFile.available()]; 
            signatureFile.read(signatureData);
            signatureFile.close();

            Signature signature = Signature.getInstance("SHA1withDSA", "SUN");
            signature.initVerify(publicKey);
            
            FileInputStream dataFile = new FileInputStream(fileName);
            BufferedInputStream bufin = new BufferedInputStream(dataFile);

            byte[] buffer = new byte[1024];
            int len;
            while((len=bufin.available())!=0) {
                bufin.read(buffer);
                signature.update(buffer,0,len);
            }
            bufin.close();dataFile.close();

            boolean isVerified;
            isVerified = signature.verify(signatureData);
            if(isVerified) {
                System.out.println("Data is verified and is correct");
            } else {
                System.err.println("Data is modified");
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}