int main () {
    
    int counter = 0;

    while (counter != 4) {
        for (int i = 0; i < 400; i++) {
            if (i <= 1)
                next = i;
            else {
                next = first + second;
                first = second;
                second = next;
                if (next % 2 == 0) {
                    counter++;
                }
            }
        }
    }

    cout << next << endl;

    return 0;

}