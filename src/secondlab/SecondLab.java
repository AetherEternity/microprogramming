/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package secondlab;

import java.awt.image.*;
import javax.imageio.*;
import java.io.*;
import java.awt.*;
import java.util.Scanner;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class SecondLab
{
	static
	{
		System.loadLibrary("ABC");
	}
	
	public static native void process(int image[]);

	public static void processImage(String inputFile, String outputFile, String outputFormat)
	{
		BufferedImage img;
		File file = new File(inputFile);

		try
		{
			img = ImageIO.read(file);
			int pixelbufer[] = new int[img.getWidth() * img.getHeight()];
			
			for(int y = 0; y < img.getHeight(); y++)
			{
				for(int x = 0; x < img.getWidth(); x++)
				{
					pixelbufer[y * img.getWidth() + x] = img.getRGB(x, y);
				}
			}
			
			process(pixelbufer);
			
			for(int y = 0; y < img.getHeight(); y++)
			{
				for(int x = 0; x < img.getWidth(); x++)
				{
					img.setRGB(x,y,pixelbufer[y * img.getWidth() + x]);
				}
			}
			
			ImageIO.write(img, outputFormat, new File(outputFile));
		}
		catch(IOException a)
		{
			System.out.println(a);
		}

	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		if(args.length!=2){
			System.out.println("Usage: start.sh inputFile.png outputFile.png");
			System.exit(0);
		}
		/*System.out.println("Enter input filename: ");
		String inputfile = sc.nextLine();
		
		System.out.println("Enter output filename: ");
		String outputfile = sc.nextLine();*/
		
		processImage(args[0], args[1], "png");
	}

}
