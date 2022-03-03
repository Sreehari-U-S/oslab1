import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
public class ser
{
static ServerSocket Serversocket;
static DataInputStream dis;
static DataOutputStream dos;
public static void main(String[] args) throws SocketException
{

try
{
int a[] = { 30, 40, 50, 60, 70, 80, 90, 100 };
Serversocket = new ServerSocket(8011);
System.out.println(&quot;waiting for connection&quot;);
Socket client = Serversocket.accept();
dis = new DataInputStream(client.getInputStream());
dos = new DataOutputStream(client.getOutputStream());
System.out.println(&quot;The number of packets sent is:&quot; + a.length);
int y = a.length;
dos.write(y);
dos.flush();
for (int i = 0; i &lt; a.length; i++)
{
dos.write(a[i]);
dos.flush();
}
int k = dis.read();
dos.write(a[k]);
dos.flush();
}
catch (IOException e)
{
System.out.println(e);
}
finally
{
try
{
dis.close();
dos.close();
}
catch (IOException e)
{
e.printStackTrace();
}
}
}
}

CLIENT SIDE
import java.lang.System;
import java.net.*;
import java.io.*;
import java.text.*;
import java.util.Random;
import java.util.*;
public class cli {
static Socket connection;
public static void main(String a[]) throws SocketException {
try {
int v[] = new int[10];
int n = 0;
Random rands = new Random();
int rand = 0;
InetAddress addr = InetAddress.getByName(&quot;Localhost&quot;);
System.out.println(addr);
connection = new Socket(addr, 8011);
DataOutputStream out = new DataOutputStream(
connection.getOutputStream());
DataInputStream in = new DataInputStream(
connection.getInputStream());

int p = in.read();
System.out.println(&quot;No of frame is:&quot; + p);
for (int i = 0; i &lt; p; i++) {
v[i] = in.read();
System.out.println(v[i]);
}
rand = rands.nextInt(p);
v[rand] = -1;
for (int i = 0; i &lt; p; i++)
{

System.out.println(&quot;Received frame is: &quot; + v[i]);
}
for (int i = 0; i &lt; p; i++)
if (v[i] == -1) {
System.out.println(&quot;Request to retransmit from packet no &quot;

+ (i+1) + &quot; again!!&quot;);

n = i;
out.write(n);
out.flush();
}

System.out.println();
v[n] = in.read();
System.out.println(&quot;Received frame is: &quot; + v[n]);

System.out.println(&quot;quiting&quot;);
} catch (Exception e) {
System.out.println(e);
}
}
}