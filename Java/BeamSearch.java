// This is my favourite code snippet because it's the first thing
// I learnt in my AI class



import java.util.Arrays;
import java.util.ArrayList;

public class BeamSearch {
	
	public static void main(String[] args) {
		Double[][] grid = gen100();
		
		//run beam search on every step size for each k 100x
		repeats(grid, 2, 0.01);
		repeats(grid, 2, 0.05);
		repeats(grid, 2, 0.1);
		repeats(grid, 2, 0.2);
		System.out.println();
		
		repeats(grid, 4, 0.01);
		repeats(grid, 4, 0.05);
		repeats(grid, 4, 0.1);
		repeats(grid, 4, 0.2);
		System.out.println();
		
		repeats(grid, 8, 0.01);
		repeats(grid, 8, 0.05);
		repeats(grid, 8, 0.1);
		repeats(grid, 8, 0.2);
		System.out.println();
		
		repeats(grid, 16, 0.01);
		repeats(grid, 16, 0.05);
		repeats(grid, 16, 0.1);
		repeats(grid, 16, 0.2);
		System.out.println();
		
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
	
	//generate 100 random coordinate points in 0<= x,y <= 100
	public static Double[][] gen100(){
		Double[][] points = new Double[100][2];
		for (int x = 0; x < 100; x ++) {
			points[x] = rand();
		}
		return points;
	}
	
	//pick k original points to start from
	public static Double[][] pickOrgs (Double[][] coords, int k){
		Double[][] orgPoints = new Double[k][2];
		for (int x = 0; x < k; x++) {
			int randOrg = (int)(Math.random()*100);
			Double[] orgPoint = coords[randOrg];
			orgPoints[x] = orgPoint;
		}
		return orgPoints;		
	}
	
	public static Double[] beamSearch (Double[][] orgPoints, Double[][] coords, Double stepSize, int k, Double max, Double count){
		count++;
		Boolean triggered = false;
		ArrayList<Double[]> neighbours = new ArrayList<Double[]>(); //array list of neighbours within step size
		Double[] neighbourVal = new Double[2];
		
		//find neighbouring values of the original points
		for (int x = 0; x < k; x++) {
			for (int y = 0; y < 100; y++) {
				Double[] currOrgPoint = orgPoints[x];
				Double[] val = coords[y];
				if((Math.abs(currOrgPoint[0] - val[0]) <= stepSize) || (Math.abs(currOrgPoint[1] - val[1]) <= stepSize)){
					neighbourVal[0] = val[0];
					neighbourVal[1] = val[1];
					neighbours.add(neighbourVal);	
				}
			}
		}
		
		//calculate the function values of all these points
		Double[][] funcVals = new Double[neighbours.size()][3];
		Double[] coordinates = new Double[2];
		for (int x = 0; x < neighbours.size(); x++) {
			coordinates = neighbours.get(x);
			
			funcVals[x][0] = coordinates[0];
			funcVals[x][1] = coordinates[1];
			funcVals[x][2] = -Math.abs(coordinates[0]-2)- Math.abs(0.5*coordinates[1]+1) +3;
			
		//	funcVals[x][2] = Math.sin((coordinates[0])/2.0) + Math.cos(2.0*coordinates[1]);
		}
		
		//sort funcVals - pick top k using bubble sort
		
		Double[][] topKs = new Double[k][3];
		
		for (int i = 0; i < funcVals.length-1; i ++) {
			for(int j = 0; j < funcVals.length-1-i; j++ ) {
				if (funcVals[j][2] > funcVals[j+1][2]) {
					Double[] temp = funcVals[j];
					funcVals[j] = funcVals[j+1];
					funcVals[j+1] = temp;
				}
			}
		}
		
		for (int i = 0; i < k; i ++) {
			topKs[i] = funcVals[i];
		}
		
		Double max2 = topKs[0][2];
		
		Double[][] returnKs = new Double[k][2];
		for (int i = 0; i < k; i ++) {
			returnKs[i][0] = topKs[i][0];
			returnKs[i][1] = topKs[i][1];
		}
		
		
		if (max2 > max) {
			triggered = true;
			max = max2;
		}
		//recurse if larger max found. 
		if (triggered == true) {
			Double[] x = beamSearch (returnKs, coords, stepSize, k, max2, count );
			count = x[0];
			max = x[1];			
		}
		else {
			Double[] returnArr = new Double[2];
			returnArr[0] = count;
			returnArr[1] = max2;
			return returnArr;// count, top f function;
		}
		return coordinates;
		
	}
	//find maximum out of our initial k points.
	public static Double initialise (int k, Double max, Double[][] grid, Double[][] orgs) {
		orgs = pickOrgs(grid, 2);
		for (int x = 0; x < orgs.length; x++) {
			Double funcVal = -Math.abs(orgs[x][0]-2)- Math.abs(0.5*orgs[x][1]+1) +3;
			//Double funcVal = Math.sin((orgs[x][0])/2.0) + Math.cos(2.0*orgs[x][1]);
			if (funcVal > max) {
				max = funcVal;	
			}
		}
		return max;
	}
	
	public static Double[][] repeats (Double[][] grid, int k, Double stepSize){
		//beamSearch (Double[][] orgPoints, Double[][] coords, Double stepSize, int k, Double max, Double count)
		//initialise (int k, Double max, Double[][] grid, Double[][] orgs)
		//[0] = count, [1] = functionValue
		
		Double[][] orgPoints = pickOrgs(grid, k);
		Double[][] runs100 = new Double[100][2];
		
		for (int i = 0; i < 100; i ++) {
			runs100[i] = beamSearch(orgPoints, grid, stepSize, k, initialise(k, 0.0, grid, orgPoints), 0.0);
		}
		
		Double meanSteps = 0.0;
		Double meanFuncVal = 0.0;
		
		for (int i = 0; i < 100; i ++) {
			meanSteps = meanSteps + runs100[i][0];
			meanFuncVal = meanFuncVal + runs100[i][1];
			}
		System.out.println("k " + k);
		System.out.println("Step size: " + stepSize);
		System.out.println("Mean Steps: " + (meanSteps)/100);
		System.out.println("Mean Func Val: " + (meanFuncVal)/100);
		
		Double sdSteps = 0.0;
		Double sdFuncVal = 0.0; 
		
		for (int i = 0; i < 100; i++) {
			sdSteps = Math.pow(runs100[i][0] - meanSteps, 2) + sdSteps;
			sdFuncVal = Math.pow(runs100[i][1]-meanFuncVal, 2) + sdFuncVal;
		}
		
		System.out.println("Standard Deviation Steps: " + Math.sqrt(sdSteps/100));
		System.out.println("Standard Deviation Function Value:)" + Math.sqrt(sdFuncVal/100));
		
		
		return orgPoints;
		}
	
}


