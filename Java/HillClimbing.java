import java.util.Arrays;
import java.util.ArrayList;

public class HillClimbing {
	public static void main(String[] args) {
		repeats();
	}
	
	//generate random coordinates
	public static Double[] rand() {
		
		Double xValue = 10*Math.random();
		Double yValue = 10*Math.random();
		
		Double[] coordinates = new Double[2];
		coordinates[0] = xValue;
		coordinates[1] = yValue;
		return coordinates;
	}
	
	//generate points random points anywhere in the coordinate grid
	public static Double[][] gen100(){
		Double[][] points = new Double[100][2];
		for (int x = 0; x < 100; x ++) {
			points[x] = rand();
		}
		return points;
	}
	
	//pick a starting point
	public static Double[] pickOrg (Double[][] coords){
		int randOrg = (int)(Math.random()*100);

		Double[] orgPoint = coords[randOrg];
		return orgPoint;
	}
	
	public static Double[] hillClimb (Double[] orgPoint, Double[][] coords, Double count, Double stepSize){
		//double stepSize = 0.2;
		count++; //count number of steps

		ArrayList<Double[]> neighbours = new ArrayList<Double[]>(); //array list to store neighbours
		Double[] neighbourVal = new Double[2];
		for (int x = 0; x < 100; x++) {
			Double[] val = coords[x];
			if ((Math.abs(orgPoint[0] - val[0]) <= stepSize) || (Math.abs(orgPoint[1] - val[1]) <= stepSize)){
					neighbourVal[0] = val[0];
					neighbourVal[1] = val[1];
					neighbours.add(neighbourVal);
			}
		}
		
		//Double max = Math.sin((orgPoint[0])/2.0) + Math.cos(2.0*orgPoint[1]);
		Double max = -Math.abs(orgPoint[0]-2)- Math.abs(0.5*orgPoint[1]+1) +3;
		Boolean triggered = false;
		for (int y = 0; y < neighbours.size(); y++) {
			Double[] coVal = neighbours.get(y);
			//Double opt = Math.sin(coVal[0]/2.0) + Math.cos(2.0*coVal[1]);
			Double opt = -Math.abs(coVal[0]-2)- Math.abs(0.5*coVal[1]+1) +3;
			
			if (opt > max) {
				max = opt;
				triggered = true;
			}
			if (triggered == true) {
				Double[] returnArr = hillClimb(coVal, coords, count, stepSize);
				count = returnArr[1];
				max = returnArr[0];	
			}
		}
		Double[] returnArr = new Double [2];
		returnArr[0] = max;
		returnArr[1] = count;
		return returnArr;
	}
	
	//repeat hill climb for 100 points on each step size. 
	public static double[][] repeats () {
		double[][] genRepeats1 = new double[100][2]; // step size 0.01
		double[][] genRepeats2 = new double[100][2]; //  step size 0.05
		double[][] genRepeats3 = new double[100][2]; // step size 0.1
		double[][] genRepeats4 = new double[100][2];  // step size 0.2

		double meanSteps = 0.0;
		double meanF1 = 0.0;
		
		double meanSteps2 = 0.0;
		double meanF12 = 0.0;
		
		double meanSteps3 = 0.0;
		double meanF13 = 0.0;
		
		double meanSteps4 = 0.0;
		double meanF14 = 0.0;
		
		Double[][] grid = gen100();
		
		
		for (int x = 0; x < 100; x ++) {
			Double[] hC = hillClimb(pickOrg(grid), grid, 0.0, 0.01);
			Double[] hC2 = hillClimb(pickOrg(grid), grid, 0.0, 0.05);
			Double[] hC3 = hillClimb(pickOrg(grid), grid, 0.0, 0.1);
			Double[] hC4 = hillClimb(pickOrg(grid), grid, 0.0, 0.2);
			
			genRepeats1[x][0] = hC[0];
			genRepeats1[x][1] = hC[1];
			meanSteps = meanSteps + hC[1];
			meanF1 = meanF1 + hC[0];
			
			genRepeats2[x][0] = hC2[0];
			genRepeats2[x][1] = hC2[1];
			meanSteps2 = meanSteps2 + hC2[1];
			meanF12 = meanF12 + hC2[0];
			
			genRepeats3[x][0] = hC3[0];
			genRepeats3[x][1] = hC3[1];
			meanSteps3 = meanSteps3 + hC3[1];
			meanF13 = meanF13 + hC3[0];
			
			genRepeats4[x][0] = hC4[0];
			genRepeats4[x][1] = hC4[1];
			meanSteps4 = meanSteps4 + hC4[1];
			meanF14 = meanF14 + hC4[0];
			
		}
		
		double sd1 = 0.0;
		double sd2 = 0.0;
		double sd3 = 0.0;
		double sd4 = 0.0;
		
		double sd11 = 0.0;
		double sd22 = 0.0;
		double sd33 = 0.0;
		double sd44 = 0.0;
		
		for (int y = 0; y < 100; y++) {
			sd1 = (((genRepeats1[y][0])- meanF1)*((genRepeats1[y][0])- meanF1)) + sd1;
			sd11 = (((genRepeats1[y][1])- meanSteps)*((genRepeats1[y][1])- meanSteps)) + sd11;
			
			sd2 = (((genRepeats2[y][0])- meanF12)*((genRepeats2[y][0])- meanF12)) + sd2;
			sd22 = (((genRepeats2[y][1])- meanSteps2)*((genRepeats2[y][1])- meanSteps2)) + sd22;
			
			sd3 = (((genRepeats3[y][0])- meanF13)*((genRepeats3[y][0])- meanF13)) + sd3;
			sd33 = (((genRepeats3[y][1])- meanSteps3)*((genRepeats3[y][1])- meanSteps3)) + sd33;
			
			sd4 = (((genRepeats4[y][0])- meanF14)*((genRepeats4[y][0])- meanF14)) + sd4;
			sd44 = (((genRepeats4[y][1])- meanSteps4)*((genRepeats4[y][1])- meanSteps4)) + sd44;
			
		}
		
		System.out.println("0.01 \n" + " meanSteps:" + meanSteps/100);
		System.out.println("meanF1:" + (meanF1/100));
		System.out.println("Standard dev F1: " + Math.sqrt(sd1/100.0));
		System.out.println("Standard dev Steps1: " + Math.sqrt(sd11/100.0));
		
		System.out.println("0.05 \n meanSteps:" + meanSteps2/100);
		System.out.println("meanF1:" + (meanF12/100));
		System.out.println("Standard dev F2: " + Math.sqrt(sd2/100.0));
		System.out.println("Standard dev Steps2: " + Math.sqrt(sd22/100.0));
		
		System.out.println("0.1 \n meanSteps:" + meanSteps3/100);
		System.out.println("meanF1:" + (meanF13/100));
		System.out.println("Standard dev F3: " + Math.sqrt(sd3/100.0));
		System.out.println("Standard dev Steps 3: " + Math.sqrt(sd33/100.0));
		
		System.out.println("0. 2 \n meanSteps:" + meanSteps4/100);
		System.out.println("meanF1:" + (meanF14/100));
		System.out.println("Standard dev F4: " + Math.sqrt(sd4/100.0));
		System.out.println("Standard dev Steps 4: " + Math.sqrt(sd44/100.0));

		return genRepeats1;
	}
	
	
}	

