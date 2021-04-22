import java.util.*;

class Dijkstra {

    int getMinIndex(boolean usedBools[], int weigth[]){
        int i, min = Integer.MAX_VALUE, minIndex = -1, noOfVertices = usedBools.length;
        for(i = 0; i < noOfVertices; i ++){
            if(!usedBools[i] && weigth[i] < min){
                min = weigth[i];
                minIndex = i;
            }
        }

        return minIndex;
    }


    void printDijkstra(boolean usedBools[], int weigth[]){
        int i, noOfVertices = usedBools.length;
        System.out.println("Vertex      Distance From source");
        for(i = 0; i< noOfVertices; i++){
            System.out.println("  " + (char)(65+i) + "              " + weigth[i]);
        }
    }


    void generateMST(int graph[][], int source) {
        int noOfVertices = graph.length;
        boolean usedBools[] = new boolean[noOfVertices];
        int weigth[] = new int[noOfVertices]; 

        int i, j;
        for(i = 0; i < noOfVertices; i ++ ){
            weigth[i] = Integer.MAX_VALUE;
            usedBools[i] = false;
        }
        
        int currentSearch;
        weigth[source] = 0;

        // noOfVertices to make last one true else noOFVerties -1
        for(i = 0; i < noOfVertices ; i ++ ){
            currentSearch = getMinIndex(usedBools, weigth);
            usedBools[currentSearch] = true;

            for(j = 0; j < noOfVertices; j ++){
                if(!usedBools[j]){
                    if( graph[currentSearch][j] != 0 && graph[currentSearch][j] + weigth[currentSearch] < weigth[j] ){
                        weigth[j] = graph[currentSearch][j] + weigth[currentSearch];
                    }
                }
            }

        }

        printDijkstra(usedBools, weigth);

    }

    public static void main(String[] args) {
        Dijkstra mst = new Dijkstra();
        Scanner sc = new Scanner(System.in);
        // Graph from ppt shared by LAB Maam
        System.out.print("Enter no of vertices: ");
        int n = sc.nextInt();
        int graph[][] = new int[n][n]; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print("Enter values: ");
                graph[i][j] = sc.nextInt();
            }         
        }
       

        // int graph[][] = new int[][] { 
        //                                 { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        //                                 { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        //                                 { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        //                                 { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        //                                 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        //                                 { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        //                                 { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        //                                 { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        //                                 { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
        //                             }; 

        // Select source
        int source = 0;
        mst.generateMST(graph, source);

            sc.close();
    }
}

/*
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0  
*/