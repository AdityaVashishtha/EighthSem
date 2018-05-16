import java.util.Scanner;

import javax.crypto.KeyGenerator;

import java.io.*;
import java.security.*;

public class GenerateSignature {

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String fileName;
        System.out.println("Enter file name to make signature of :");
        fileName = scan.next();
        //System.out.println(fileName);  
        try {
            //Algorithm and provider
            KeyPairGenerator keyGen = KeyPairGenerator.getInstance("DSA", "SUN");
            SecureRandom random = SecureRandom.getInstance("SHA1PRNG","SUN");
            keyGen.initialize(1024,random);
            KeyPair keyPair = keyGen.generateKeyPair();
            PrivateKey privateKey = keyPair.getPrivate();
            PublicKey publicKey = keyPair.getPublic();

            Signature signature = Signature.getInstance("SHA1withDSA", "SUN");
            signature.initSign(privateKey);

            //Reading from file to create signatur
            FileInputStream fin = new FileInputStream(fileName);
            BufferedInputStream bufin = new BufferedInputStream(fin);
            byte[] buffer = new byte[1024];
            int len;
            while ((len = bufin.read(buffer)) >= 0) {
                signature.update(buffer, 0, len);
            };
            bufin.close();
            byte[] signatureData = signature.sign();
            //System.out.println(signatureData);
            
            FileOutputStream signatureFileOutput = new FileOutputStream("sig_file");
            signatureFileOutput.write(signatureData);
            signatureFileOutput.close();

            FileOutputStream publicKeyFileOutput = new FileOutputStream("pub_file");
            publicKeyFileOutput.write(publicKey.getEncoded());
            publicKeyFileOutput.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}