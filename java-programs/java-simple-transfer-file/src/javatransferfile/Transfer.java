/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javatransferfile;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.net.DatagramSocket;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 *
 * @author melati
 */
public class Transfer {

    private String ipClient = "";
    private String fileName = "";
    private String path = "";
    private static int port;
    public TransferGUI view;

    public Transfer(TransferGUI view) {
        this.view = view;
        this.setIP();
        this.setPath();
        this.showClientDirectory();
        this.pindah();
        this.download();
        this.upload();
    }

//    METHOD FOR ACTION LISTENER
    private void pindah() {
        this.view.getBtnPindah().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //set path ketika berpindah direktori
                getPath();
                //mengkosongkan textArea setelah pindah direktori
                view.getjTextArea1().setText("");
                //menampilkan direktori yang baru setelah pindah
                showClientDirectory();
            }
        });
    }

    private void download() {
        this.view.getBtnDownload().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //mendapatkan nama file yang akan didownload
                fileName = JOptionPane.showInputDialog(null, "Masukkan nama file yang akan di download : ");

                //mendapatkan path file yang akan didownload
                path = getPath() + "/" + fileName;

                //baca isi dari file txt sebelum didownload
                readFileBeforeDownload();
            }
        });
    }

    private void upload() {
        this.view.getBtnUpload().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //pilih file yang akan diupload
                chooseFileToUpload();
            }
        });
    }

    public String setPath() {
        path = "//" + ipClient + "/public";
        return path;
    }

    public String getPath() {
        return path = "//" + ipClient + view.getjTextField1().getText();
    }

    void setIP() {
        //kode program untuk set ip client
        String ipTujuan = JOptionPane.showInputDialog(null, "Masukkan IP tujuan : ");
        if (ipTujuan != null) {
            ipClient = ipTujuan;
        } else {
            System.exit(0);
        }
    }

    public static void setPort() {
        //kode program untuk set port yang akan digunakan
        String inputPort = JOptionPane.showInputDialog("Masukkan port");
        if (inputPort != null) {
            while (availablePort(Integer.parseInt(inputPort)) != true) {
                JOptionPane.showMessageDialog(null, "Ups, Port telah digunakan, ganti port lainya!");
                inputPort = JOptionPane.showInputDialog("Masukkan port tujuan");
            }
            port = Integer.parseInt(inputPort);
        } else {
            System.exit(0);
        }
    }

    static boolean availablePort(int port) {
        //kode program untuk 
        ServerSocket ss = null;
        DatagramSocket ds = null;
        try {
            ss = new ServerSocket(port);
            ss.setReuseAddress(true);
            ds = new DatagramSocket(port);
            ds.setReuseAddress(true);
            return true;
        } catch (IOException e) {
        } finally {
            if (ds != null) {
                ds.close();
            }

            if (ss != null) {
                try {
                    ss.close();
                } catch (IOException e) {
                    /* should not be thrown */
                }
            }
        }
        return false;
    }

    void readFileBeforeDownload() {
        //kode program untuk membaca file terlebih dahulu sebelum download
        String dataTemp;
        String data = "";
        System.out.println(path);
        try {
            FileReader fr = new FileReader(path);
            BufferedReader br = new BufferedReader(fr);
            while ((dataTemp = br.readLine()) != null) {
                data = data + dataTemp + "\n";
            }
            chooseDowloadFileDirectory(data);
            br.close();
        } catch (IOException e) {
            System.out.println(e);
            JOptionPane.showMessageDialog(view, "Ups! sepertinya file tidak ada.");
        }
    }

    void chooseDowloadFileDirectory(String data) {
        //kode program untuk memilih direktori untuk file yang didownload
        JFileChooser fc = new JFileChooser();
        fc.setDialogTitle("Tentukan direktori file download di komputer kamu");
        int userSelection = fc.showSaveDialog(null);
        if (userSelection == JFileChooser.APPROVE_OPTION) {
            path = fc.getSelectedFile().getPath();
            File fileToSave = fc.getSelectedFile();
            if (fileToSave.exists()) {
                int result = JOptionPane.showConfirmDialog(null, "File sudah ada, timpa?", "File sudah ada", JOptionPane.OK_CANCEL_OPTION);
                switch (result) {
                    case JOptionPane.YES_OPTION:
                        downloadFile(data);
                    case JOptionPane.CANCEL_OPTION:
                }
            } else {
                downloadFile(data);
            }
        }
    }

    void downloadFile(String data) {
        //kode program proses download file
        System.out.println("method downloadFile");
        try {
            FileWriter fw = new FileWriter(path);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(data);
            bw.flush();
            bw.close();
            JOptionPane.showMessageDialog(null, "Download berhasil!");
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Download gagal!");
            JOptionPane.showMessageDialog(null, e);
        }
    }

    void chooseFileToUpload() {
        //kode program memilih file yang akan diupload
        JFileChooser fc = new JFileChooser();
        fc.setDialogTitle("Pilih file yang akan diupload");
        int userSelection = fc.showDialog(null, "Upload");

        if (userSelection == JFileChooser.APPROVE_OPTION) {
            path = "//" + ipClient + view.getjTextField1().getText() + "/" + fc.getSelectedFile().getName();
            System.out.println(path);
            uploadFile(fc.getSelectedFile().getPath());
        }
    }

    void uploadFile(String path) {
        //kode program untuk upload file
        String dataTemp;
        String data = this.path + "\n";
        try {
            Socket sk = new Socket(ipClient, port);
            FileReader fr = new FileReader(path);
            System.out.println("up path = " + path);

            BufferedReader br = new BufferedReader(fr);
            while ((dataTemp = br.readLine()) != null) {
                data = data + dataTemp + "\n";
            }
            DataOutputStream dos = new DataOutputStream(sk.getOutputStream());
            dos.writeBytes(data);
            br.close();
            JOptionPane.showMessageDialog(view, "Upload Berhasil!");

        } catch (IOException e) {
            JOptionPane.showMessageDialog(view, "Ups! sepertinya upload gagal.");
            JOptionPane.showMessageDialog(view, e);
            System.out.println(e);
        }
    }

    public static void receiveFile() {
        //kode program untuk menerima file yang diupload client
        try {
            ServerSocket ss = new ServerSocket(port);
            String data = "";
            String downloadPath = "";
            while (true) {
                Socket sk = ss.accept();
                DataInputStream dis = new DataInputStream(sk.getInputStream());
                downloadPath = dis.readLine();
                while (dis.available() > 0) {
                    data = data + dis.readLine() + "\n";
                }
                System.out.println(downloadPath);
                FileWriter fw = new FileWriter(downloadPath);
                BufferedWriter bw = new BufferedWriter(fw);
                bw.write(data);
                bw.flush();
                bw.close();
                dis.close();
                data = "";
                downloadPath = "";
            }
        } catch (Exception e) {
            System.out.println("gagal receive");
            System.out.println(e);
        }
    }

    void showClientDirectory() {
        //kode program untuk menampilkan directory yang ada di pc client
        System.out.println(path);
        File file = new File(path);
        File[] files = file.listFiles();
        for (File file1 : files) {
            if (!file1.isHidden()) {
                view.getjTextArea1().append(file1.getName() + "\n");
            }
        }
    }

}
