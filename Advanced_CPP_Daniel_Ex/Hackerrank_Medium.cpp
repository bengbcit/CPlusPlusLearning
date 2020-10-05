/* Attribute Parser 
*	Reference from Isaac Asante
*   https://gist.github.com/IsaacAsante/82259bb87d10204f6a0e4e4b3cf4ba6e
*/
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n, q;
//    string curr, attr_name = "";    // new way declare string
//    map<string, string> m;          // pair of key(string), value(string)
//    cin >> n >> q;
//    cin.ignore();                   // igonre '\n'
//
//    for (int i = 0; i < n;++i) {
//        string line, tag, word;
//        cin >> line;
//        stringstream ss(line);
//       
//        while(ss >> word)  {        // extract each part by a delim ' '; 
//            switch (word[i]) {
//            case '<':
//                cout << word << endl;
//                break;
//            case '=':
//                cout << word << endl;
//                break;
//            case '"':
//                cout << word << endl;
//                break;
//            default: // for tag name
//                cout << word << endl;
//            }
//            
//        }
//
//    }
//    
//
//
//    return 0;
//}

//cin.ignore()的用法

//int main()
//{
//	char str[30];
//	cout << "请输入一个字符串：";
//	cin >> str;
//	cout << str << endl;
//
//
//	cin.ignore(100, '\n');
//	cout << "请输入任意字符结束程序！\n";
//	cin.get();
//
//	return 0;
//}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    string curr = "", attr_name;
    map<string, string> m;
    cin >> n >> q;
    cin.ignore();

    // For every word in the HRML Line (space delimiter), check:
    for (int i = 0; i < n; i++) {
        string line, tag, extract;
        getline(cin, line);
        stringstream ss(line);

        // Process the HRML lines
        while (ss>>extract) {
            // If it's a tag
            switch (extract[0]){
                case'<':
                    // If it's an opening tag
                    if (extract[1] != '/') {
                        // Remove the opening bracket
                        tag = extract.substr(1);
                        // For tags without attributes
                        if (tag[tag.length() - 1] == '>') {
                            // Remove the closing bracket
                            tag.pop_back();
                        }
                        // Check if any nesting is needed
                        if (curr.size() > 0) {
                            // Nest this tag : previous + current tag
                            curr += "." + tag;
                        }
                        else {
                            curr = tag;
                        }
                       
                    }
                    // If it's a closing tag
                    else {
                        tag = extract.substr(2, (extract.find('>') - 2));
                        // Check if a nested tag has to be closed
                        size_t pos = curr.find("." + tag);
                        if (pos != string::npos /*Maximum value for size_t*/) { 
                            // Remove the nested tag
                            curr = curr.substr(0, pos);
                        }
                        else {
                            // All tags are closed
                            curr = "";
                        }
                    }
                    break;

                // If's an attribute's value
                case'"':
                    // Capture the full value
                    size_t pos = extract.find_last_of('"');
                    string attr_value = extract.substr(1, pos - 1);
                    // Add to the map
                    m[attr_name] = attr_value;
                    
                    break;         
            }
            if (extract != "=") {
                // It's definitely an attribute name
                attr_name = curr + "~" + extract;
               
            }
        }
    }

    // Get the values with the queries
    string query;
    for (int i = 0; i < q; i++) {
        getline(cin, query);

        // Search in the map
        map<string, string>::iterator itr = m.find(query);
        if (itr != m.end()) {// itrerator search before end, find it
            cout << itr->second << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}