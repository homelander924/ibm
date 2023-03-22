import java.io.*;

class Student {
    String usn, name, programme;
    long ph;

    Student() {
        usn = name = programme = "No value";
        ph = 0;
    }

    void read_data(String u, String n, String p, long m) {
        usn = u;
        name = n;
        programme = p;
        ph = m;
    }

    void display() {
        System.out.println(usn + "\t" + name + "\t" + programme + "\t\t" + ph);
    }
}

class pgm3 {
    public static void main(String args[]) throws Exception

    {
        String u, n, p;
        long m;
        int no;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter number of records:");
        no = Integer.parseInt(br.readLine());
        Student[] s = new Student[no];

        for (int i = 0; i < s.length; i++) {
            System.out.println("\nEnter Student " + (i + 1) + " record");
            s[i] = new Student();

            System.out.print("Enter student USN: ");
            u = br.readLine();

            System.out.print("Enter student Name: ");
            n = br.readLine();

            System.out.print("Enter student Programme: ");
            p = br.readLine();

            System.out.print("Enter student Phone number: ");
            m = Long.parseLong(br.readLine());
            s[i].read_data(u, n, p, m);
        }

        System.out.println("USN \t NAME \t PROGRAMME \t PHONE NO");
        for (int i = 0; i < s.length; i++) {
            s[i].display();
        }
    }
}