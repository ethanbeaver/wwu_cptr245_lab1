void parseStudentName(const string studentName, string& firstName, string& lastName, string& username) {
    // name length requirements
    const unsigned long LAST_LENGTH = 4;
    const unsigned long FIRST_LENGTH = 2;

    // clear pass by reference values
    lastName.clear();
    firstName.clear();
    username.clear();

    // empty studentName
    if (studentName.length() == 0) throw "Missing name/s";

    // parse studentName
    unsigned int spaceCount = 0; // space count in studentName
    for (int c = 0; c < studentName.length(); c++) {
        if (studentName[c] == ' ') spaceCount++; // found space
        else if (spaceCount == 0) firstName.push_back(studentName[c]); // build firstName
        else if (spaceCount == 1) lastName.push_back(studentName[c]); // build lastName
        else throw "Too many names"; // more than one space
    }

    // exceptions
    if (lastName.length() == 0 || firstName.length() == 0) throw "Missing name/s";

    // adjusted letter counts for username
    unsigned long userLastCount = min(lastName.length(), LAST_LENGTH);
    unsigned long userFirstCount = min(firstName.length(), FIRST_LENGTH);

    // add more characters from first name
    if(userLastCount < LAST_LENGTH && userFirstCount >= FIRST_LENGTH) {
        userFirstCount += LAST_LENGTH - userLastCount;
    }
        // add more characters from last name
    else if(userFirstCount < FIRST_LENGTH && userLastCount >= LAST_LENGTH) {
        userLastCount += FIRST_LENGTH - userFirstCount;
    }

    // add last name characters to username
    for(int c = 0; c < userLastCount; c++) {
        username.push_back(char(tolower(lastName[c])));
    }
    // add first name characters to username
    for(int c = 0; c < userFirstCount; c++) {
        username.push_back(char(tolower(firstName[c])));
    }
}