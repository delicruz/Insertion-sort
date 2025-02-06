#include <graphics.h> 
#include <conio.h>      
#include <iostream>
#include <cstdlib>      

using namespace std;

// Screen dimensions (typical 640x480 for old BGI; adjust if needed)
const int WIDTH  = 640;
const int HEIGHT = 480;

// Function to draw the entire array as bars
void drawArray(const int arr[], int n, int highlightIdx = -1, int highlightIdx2 = -1) {
    // Clear the screen area (draw a white rectangle over the entire screen)
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, WIDTH, HEIGHT);

    // Some padding between bars
    int barWidth = WIDTH / n;

    // Find the maximum value (for height scaling)
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    if (maxVal == 0) maxVal = 1; // Avoid division by zero

    for(int i = 0; i < n; i++) {
        // Position and height
        int barHeight = (int)(( (double)arr[i] / maxVal) * (HEIGHT - 50)); 
        // (HEIGHT-50) so we leave some space at the top

        int x1 = i * barWidth;
        int y1 = HEIGHT - barHeight;  // bars grow upward from the bottom
        int x2 = x1 + barWidth - 1;
        int y2 = HEIGHT;

        // - highlight the bar with a different color if it's the one being "examined"
        if(i == highlightIdx || i == highlightIdx2) {
            setfillstyle(SOLID_FILL, RED);   // highlight color
        } else {
            setfillstyle(SOLID_FILL, BLUE);  // normal color
        }

        // Draw the bar
        bar(x1, y1, x2, y2);

        // Optional: draw a border around the bar
        setcolor(BLACK);
        rectangle(x1, y1, x2, y2);

        // Reset color for next shapes
        setcolor(BLACK);
    }

    // Update screen
    delay(300);  // small pause so we can see the changes (300 ms)
}

// Insertion sort with visualization
void insertionSortVisual(int arr[], int n) {
    // Draw initial array
    drawArray(arr, n);

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            // Visualize comparison (highlight arr[j] and arr[j+1])
            drawArray(arr, n, j, j+1);

            // Shift the bar at j to j+1
            arr[j + 1] = arr[j];
            j--;

            // Redraw after shifting
            drawArray(arr, n, j+1);
        }
        arr[j + 1] = key;

        // Final position of key after insertion
        drawArray(arr, n, j+1);
    }
}

static void initCenteredWindow(int windowWidth, int windowHeight, const char *title) {
        int screenWidth = 2560;  // 2K Screen Width
        int screenHeight = 1600; // 2K Screen Height

        // Adjust for centering
        int x = (screenWidth - windowWidth) / 2 - 610;
        int y = (screenHeight - windowHeight) / 2 - 410;

        initwindow(windowWidth, windowHeight, title, x, y);
    }

int main() {
   // Initialize the graphics window
  initCenteredWindow(630, 490, "Visual");

    // Read array size
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if(n <= 0) {
        cout << "Invalid size!" << endl;
        closegraph();
        return 0;
    }

    // Create array dynamically
    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertionSortVisual(arr, n);

    cout << "Press any key in the graphics window to exit..." << endl;
    getch();        // Wait for a key press
    closegraph();   // Close the graphics mode

    delete[] arr;
    return 0;
}
