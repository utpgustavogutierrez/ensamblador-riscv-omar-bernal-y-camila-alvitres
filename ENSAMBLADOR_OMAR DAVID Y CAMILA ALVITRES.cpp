//OMAR DAVID BERNAL - CAMILA ALVITRES
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <bitset>
#ifndef LIST_HH
#define LIST_HH
#include <iostream>

//-----------------------------------------------------------------------------------------
//------------------------------------ classes --------------------------------------------
//-----------------------------------------------------------------------------------------

//Description of every single instruction. 
class InstruccionEnEspecifico {
private:
    std::string nombreInstruccion;
    std::string funct3;
    std::string func7;

public:
    // Constructor
    InstruccionEnEspecifico(const std::string& nombre, const std::string& funct3, const std::string& func7)
        : nombreInstruccion(nombre), funct3(funct3), func7(func7) {}

    std::tuple<std::string, std::string> obtenerDatos() const {
        return std::make_tuple(funct3, func7);
    }
    std::string obtenerNombreInstruccion() const {
        return nombreInstruccion;
    }
    std::string obtenerFunct3Instruccion() const {
        return funct3;
    }
    std::string obtenerFunct7Instruccion() const {
        return func7;
    }
};

//Description of a class for classes. On this case we'll save all the data from groups of instrucctions
class TipoInstruccion {
private:
    std::string OpCode;
    std::vector<InstruccionEnEspecifico> listaInstrucciones;

public:
    // Constructor
    TipoInstruccion(const std::string& OpCode, const std::vector<InstruccionEnEspecifico>& listaInstrucciones)
        : OpCode(OpCode), listaInstrucciones(listaInstrucciones) {}
    
    //We can search for an word to obtain the parameters from that class
    std::tuple<std::string, std::string> obtenerFunct3y7(const std::string& palabra) const {
        for (const auto& instruccion : listaInstrucciones) {
            if (instruccion.obtenerNombreInstruccion() == palabra) {
                return std::make_tuple(instruccion.obtenerFunct3Instruccion(), instruccion.obtenerFunct7Instruccion());
            }
        }
        //If the word doesn't exist, returns empty spaces
        return std::make_tuple("", "");
    }
    
    std::string obtenerOpCode() const {
        return OpCode;
    }
    
    std::tuple<std::string, std::string, std::string> obtenerRegistros(const std::string& instruccion) const {
        std::stringstream ss(instruccion); //Change the type
        std::string op, rs1, rs2, rd;
        
        // Ignore the first word
        ss >> op;
        
        // Extraer los registros
        ss.ignore(1); // Ignorar el espacio después de la operación
        std::getline(ss, rd, ',');
        ss >> rs1;
        ss.ignore(1); // Ignorar la coma
        ss >> rs2;
        
        return std::make_tuple(rs1, rs2, rd);
    }
    
    bool instruccionExists(const std::string& palabra) const {
        for (const auto& instruccion : listaInstrucciones) {
            if (instruccion.obtenerNombreInstruccion() == palabra) {
                return true;
            }
        }
        return false;
    }
};


//-----------------------------------------------------------------------------------------
//--------------------------------- general functions -------------------------------------
//-----------------------------------------------------------------------------------------
std::string decimalToBinary(int n) {
    std::string binaryString = std::bitset<20>(n).to_string();
    size_t startPos = binaryString.find_first_of('1');
    if (startPos != std::string::npos) {
        return binaryString.substr(startPos);
    }
    return "0";
}

std::string registerToBinary(const std::string& reg) {
    if (reg == "x0" || reg == "zero") {
        return "00000";
    } else if (reg == "x1" || reg == "ra") {
        return "00001";
    } else if (reg == "x2" || reg == "sp") {
        return "00010";
    } else if (reg == "x3" || reg == "gp") {
        return "00011";
    } else if (reg == "x4" || reg == "tp") {
        return "00100";
    } else if (reg == "x5" || reg == "t0") {
        return "00101";
    } else if (reg == "x6" || reg == "t1") {
        return "00110";
    } else if (reg == "x7" || reg == "t2") {
        return "00111";
    } else if (reg == "x8" || reg == "s0" || reg == "fp") {
        return "01000";
    } else if (reg == "x9" || reg == "s1") {
        return "01001";
    } else if (reg == "x10" || reg == "a0") {
        return "01010";
    } else if (reg == "x11" || reg == "a1") {
        return "01011";
    } else if (reg == "x12" || reg == "a2") {
        return "01100";
    } else if (reg == "x13" || reg == "a3") {
        return "01101";
    } else if (reg == "x14" || reg == "a4") {
        return "01110";
    } else if (reg == "x15" || reg == "a5") {
        return "01111";
    } else if (reg == "x16" || reg == "a6") {
        return "10000";
    } else if (reg == "x17" || reg == "a7") {
        return "10001";
    } else if (reg == "x18" || reg == "s2") {
        return "10010";
    } else if (reg == "x19" || reg == "s3") {
        return "10011";
    } else if (reg == "x20" || reg == "s4") {
        return "10100";
    } else if (reg == "x21" || reg == "s5") {
        return "10101";
    } else if (reg == "x22" || reg == "s6") {
        return "10110";
    } else if (reg == "x23" || reg == "s7") {
        return "10111";
    } else if (reg == "x24" || reg == "s8") {
        return "11000";
    } else if (reg == "x25" || reg == "s9") {
        return "11001";
    } else if (reg == "x26" || reg == "s10") {
        return "11010";
    } else if (reg == "x27" || reg == "s11") {
        return "11011";
    } else if (reg == "x28" || reg == "t3") {
        return "11100";
    } else if (reg == "x29" || reg == "t4") {
        return "11101";
    } else if (reg == "x30" || reg == "t5") {
        return "11110";
    } else if (reg == "x31" || reg == "t6") {
        return "11111";
    } else {
        std::stringstream ss(reg);
        int num = 0;
        ss >> num;
        // Convertir el número a su representación binaria y devolverlo
        return std::bitset<20>(num).to_string();
    }
}

void printBinaryToHex(const std::string& binary) {
    bool turno = false;
    for (size_t i = 0; i < binary.length(); i += 4) {
        if (turno == false){
            turno = true;
            std::cout<<" ";
        }
        else{
            turno = false;
        }
        
        if (binary.substr(i, 4) == "0000") {
            std::cout << "0";
        } else if (binary.substr(i, 4) == "0001") {
            std::cout << "1";
        } else if (binary.substr(i, 4) == "0010") {
            std::cout << "2";
        } else if (binary.substr(i, 4) == "0011") {
            std::cout << "3";
        } else if (binary.substr(i, 4) == "0100") {
            std::cout << "4";
        } else if (binary.substr(i, 4) == "0101") {
            std::cout << "5";
        } else if (binary.substr(i, 4) == "0110") {
            std::cout << "6";
        } else if (binary.substr(i, 4) == "0111") {
            std::cout << "7";
        } else if (binary.substr(i, 4) == "1000") {
            std::cout << "8";
        } else if (binary.substr(i, 4) == "1001") {
            std::cout << "9";
        } else if (binary.substr(i, 4) == "1010") {
            std::cout << "A";
        } else if (binary.substr(i, 4) == "1011") {
            std::cout << "B";
        } else if (binary.substr(i, 4) == "1100") {
            std::cout << "C";
        } else if (binary.substr(i, 4) == "1101") {
            std::cout << "D";
        } else if (binary.substr(i, 4) == "1110") {
            std::cout << "E";
        } else if (binary.substr(i, 4) == "1111") {
            std::cout << "F";
        } else {
            std::cout << " "; // Imprime un espacio en blanco si el binario no es válido
        }
    }
    std::cout << std::endl;
}


std::vector<TipoInstruccion> preparacionDeClases(){
    
    //Instrucciones tipo R
    std::vector<InstruccionEnEspecifico> listaInstruccionesTipoR = {
        InstruccionEnEspecifico("add", "000", "0000000"),
        InstruccionEnEspecifico("sub", "000", "0100000"),
        InstruccionEnEspecifico("sll", "001", "0000000"),
        InstruccionEnEspecifico("slt", "010", "0000000"),
        InstruccionEnEspecifico("sltu", "011", "0000000"),
        InstruccionEnEspecifico("xor", "100", "0000000"),
        InstruccionEnEspecifico("srl", "101", "0000000"),
        InstruccionEnEspecifico("sra", "101", "0100000"),
        InstruccionEnEspecifico("or", "110", "0000000"),
        InstruccionEnEspecifico("and", "111", "0000000")
    };
    TipoInstruccion tipoR("0110011", listaInstruccionesTipoR);
    
    //Instrucciones tipo I
    std::vector<InstruccionEnEspecifico> listaInstruccionesTipoI = {
        InstruccionEnEspecifico("addi", "000", ""),
        InstruccionEnEspecifico("slli", "001", ""),
        InstruccionEnEspecifico("slti", "010", ""),
        InstruccionEnEspecifico("sltiu", "011", ""),
        InstruccionEnEspecifico("xori", "100", ""),
        InstruccionEnEspecifico("srli", "101", ""),
        InstruccionEnEspecifico("srai", "101", ""),
        InstruccionEnEspecifico("ori", "110", ""),
        InstruccionEnEspecifico("andi", "111", "")
    };
    TipoInstruccion tipoI("0010011", listaInstruccionesTipoI);
    
    //Instrucciones tipo I - Lectura
    std::vector<InstruccionEnEspecifico> listaInstruccionesTipoI2 = {
        InstruccionEnEspecifico("lb", "000", ""),
        InstruccionEnEspecifico("lh", "001", ""),
        InstruccionEnEspecifico("lw", "010", ""),
        InstruccionEnEspecifico("lbu", "100", ""),
        InstruccionEnEspecifico("lhu", "101", "")
    };
    TipoInstruccion tipoI2 ("0000011", listaInstruccionesTipoI2);
    
    //Instrucciones tipo S
    std::vector<InstruccionEnEspecifico> listaInstruccionesTipoS = {
        InstruccionEnEspecifico("sb", "000", ""),
        InstruccionEnEspecifico("sh", "001", ""),
        InstruccionEnEspecifico("sw", "010", "")
    };
    TipoInstruccion tipoS("0100011", listaInstruccionesTipoS);

    //Instrucciones tipo B
    std::vector<InstruccionEnEspecifico> listaInstruccionesTipoB = {
        InstruccionEnEspecifico("beq", "000", ""),
        InstruccionEnEspecifico("bne", "001", ""),
        InstruccionEnEspecifico("blt", "100", ""),
        InstruccionEnEspecifico("bge", "101", ""),
        InstruccionEnEspecifico("bltu", "110", ""),
        InstruccionEnEspecifico("bgeu", "111", "")
    };
    TipoInstruccion tipoB("1100011", listaInstruccionesTipoB);
    
    std::vector<TipoInstruccion> listaTiposInstrucciones = {tipoR, tipoI, tipoI2, tipoS, tipoB};
    
    return listaTiposInstrucciones;
    }

//-----------------------------------------------------------------------------------------
//------------------------------ description of lists -------------------------------------
//-----------------------------------------------------------------------------------------

// Template to create a list
template<typename T>
class List {
    
private:
    //List Nodes
    class Node {
    private:
        Node* nextNode; // Pointer to the next node (Element -> Element -> Element)
        T instData; // The instruction in string
        mutable std::string typeLine;
        mutable std::string direction;

    public:
        Node() : nextNode(nullptr), instData(T()) {}

        Node(const T& d) : nextNode(nullptr), instData(d) {}

        void setNext(Node* p) { nextNode = p; }

        Node* getNext() { return nextNode; }

        const T& getData() const {
            return instData;
        }
        
        std::string getDirection(){
            return direction;
        }
        
        //Return the name of the instrucction
        std::string extractFirstWord() const {
            size_t posFinal = instData.find(' ');
            if (posFinal == std::string::npos)
                return instData;
            return instData.substr(0, posFinal);
        }
        
        //Is a checker for the instructions, for just keep the needed
        bool isFirstWordValid(const std::vector<TipoInstruccion>& listaTiposInstrucciones) const {
            std::string firstWord = extractFirstWord();
            // Check if it is in the class
            for (const auto& tipoInstruccion : listaTiposInstrucciones) {
                if (tipoInstruccion.instruccionExists(firstWord)) {
                    typeLine = "Inst";
                    return true;
                }
            }
            // Check if it is a label ("word"+":)
            size_t colonPos = instData.find(':');
            if (colonPos != std::string::npos && colonPos+2 == firstWord.length()){ // Se comprueba si el ':' está justo después de la primera palabra
                typeLine = "Label";
                return true;
            } 
            return false;
        }
        
        void assignMemoryAddress(int& memoryAddress) {
            if (typeLine == "Inst") {
                memoryAddress += 4;
                direction = std::to_string(memoryAddress);
            } else if (typeLine == "Label") {
                memoryAddress += 196;
                direction = std::to_string(memoryAddress);
            }
        }
            
        std::string getMemoryAddress() const {
            return direction;
        }
        
        std::string getTypeLine() const {
            return typeLine;
        }
    };

    // Atributos para la Lista
    Node* first_; // Pointer to the first node
    Node* last_; // Pointer to the last node
    unsigned int size_; // Size of the list

public:
    // Constructor para Lista
    List() : first_(nullptr), last_(nullptr), size_(0) {}

    // Devuelve el tamaño de la lista
    unsigned int size() const { return size_; }

    // Verifica si la lista está vacía
    bool empty() { 
        return first_ == nullptr;
    }
    
    //Delete everything that's not a Instruction or a Label
    void removeInvalidLines(const std::vector<TipoInstruccion>& listaTiposInstrucciones) {
        Node* current = first_;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (!current->isFirstWordValid(listaTiposInstrucciones)) {
                Node* temp = current;
                current = current->getNext();
                removeNode(prev, temp);
            } else {
                prev = current;
                current = current->getNext();
            }
        }
    }
    
    void assignMemoryAddresses() {
        int memoryAddress = -100;
        Node* current = first_;
        while (current != nullptr) {
            current->assignMemoryAddress(memoryAddress);
            current = current->getNext();
        }
    }
    
    //Delete the label after we get their information
    std::vector<std::pair<std::string, std::string>> depurationLabel() {
        std::vector<std::pair<std::string, std::string>> labels;
        Node* current = first_;
        Node* prev = nullptr;
        
        while (current != nullptr) {
            if (current->getTypeLine() == "Label") {
                std::string labelName = current->extractFirstWord();
                // Eliminar el último carácter (que es ':')
                labelName = labelName.substr(0, labelName.size() - 2);
                labels.push_back(std::make_pair(labelName, current->getMemoryAddress()));
                Node* temp = current;
                current = current->getNext();
                removeNode(prev, temp);
            } else {
                prev = current;
                current = current->getNext();
            }
        }
        return labels;
    }

    // Adds an item to the last of the list
    void push_back(const T& elem) {
        Node* n = new Node(elem);
        if (empty()) {
            first_ = n;
        } else {
            last_->setNext(n);
        }
        last_ = n;
        size_++;
    }

    // Adds an item to the start of the list
    void push_front(const T& elem) {
        Node* n = new Node(elem);
        if (empty()) {
            first_ = n;
            last_ = n;
        } else {
            n->setNext(first_);
            first_ = n;
        }
        size_++;
    }

    void removeNode(Node* prev, Node* current) {
        if (prev == nullptr) {
            first_ = current->getNext();
        } else {
            prev->setNext(current->getNext());
        }
        if (current == last_) {
            last_ = prev;
        }
        delete current;
        size_--;
    }

    // Prints the list
     void print() {
        if (empty()) {
            std::cout << "< >" << std::endl;
            return;
        }
        Node* p = first_;
        while (p != nullptr) {
            std::cout << "Address: " << p->getMemoryAddress() << " - Instruction: " <<p->getData() << std::endl;
            p = p->getNext();
        }
    }
    
    //Transforms the code to binary, and the binary to hexadecimal and print the result
    void traduccion(const std::vector<TipoInstruccion>& listaTiposInstrucciones, const std::vector<std::pair<std::string, std::string>>& labels){
        Node* current = first_;
        while (current != nullptr) {
            std::string instruccion = current->getData();
            std::string primeraPalabra = current->extractFirstWord();
            bool found = false;
            
            for (const auto& tipoInstruccion : listaTiposInstrucciones) {
                std::tuple<std::string, std::string> functs = tipoInstruccion.obtenerFunct3y7(primeraPalabra);
                std::string funct3 = std::get<0>(functs);
                std::string func7 = std::get<1>(functs);
                if (funct3 != "") { // Si encontramos una coincidencia
                    std::string opCode = tipoInstruccion.obtenerOpCode();
                    std::tuple<std::string, std::string, std::string> registros = tipoInstruccion.obtenerRegistros(instruccion);
                    
                    //Se conforma la instrucción
                    std::string binaryInstruction = "";
                    
                    //Type R
                    if (opCode == "0110011"){
                        std::string rs2 = registerToBinary(std::get<1>(registros));
                        std::string rd = registerToBinary(std::get<2>(registros));
                        
                        std::string rs1WithComma = std::get<0>(registros);
                        rs1WithComma = rs1WithComma.substr(0, rs1WithComma.size() - 1);
                        std::string rs1 = registerToBinary(rs1WithComma);
                        
                        binaryInstruction = func7+rs2+rs1+funct3+rd+opCode;
                    }
                    
                    //Type I
                    else if (opCode == "0010011" || opCode == "0000011"){
                        std::string rs2 = registerToBinary(std::get<1>(registros));
                        rs2 = rs2.substr(rs2.length() - 12);
                        
                        std::string rd = registerToBinary(std::get<2>(registros));
                        
                        std::string rs1WithComma = std::get<0>(registros);
                        rs1WithComma = rs1WithComma.substr(0, rs1WithComma.size() - 1);
                        std::string rs1 = registerToBinary(rs1WithComma);
                        
                        binaryInstruction = rs2.substr(0,12)+rs1+funct3+rd+opCode;
                    }
                    
                    //Type S
                    else if (opCode == "0100011"){
                        std::string rs2 = registerToBinary(std::get<2>(registros));
                        std::string rs1 = registerToBinary(std::get<1>(registros));
                        
                        std::string rdWithComma = std::get<0>(registros);
                        rdWithComma = rdWithComma.substr(0, rdWithComma.size() - 1);
                        std::string rd = registerToBinary(rdWithComma);
                        
                        
                        if (rd.length() > 12) {
                            rd = rd.substr(rd.length() - 12);
                        } else {
                            while (rd.length() < 12) {
                                rd = "0" + rd;
                            }
                        }

                        binaryInstruction = rd.substr(0,7) + rs2 + rs1 + funct3 + rd.substr(7,5) + opCode;
                    }
                    
                    //Type B
                    else if (opCode == "1100011"){
                        std::string rs1 = registerToBinary(std::get<2>(registros));
                        
                        std::string rs2WithComma = std::get<0>(registros);
                        rs2WithComma = rs2WithComma.substr(0, rs2WithComma.size() - 1);
                        std::string rs2 = registerToBinary(rs2WithComma);
                    
                        std::string rd = std::get<1>(registros);
                        for (const auto& label : labels) {
                            if (rd == label.first) {
                                int directionActual = std::stoi(current->getDirection(), nullptr, 16);
                                int directionToGo = std::stoi(label.second, nullptr, 16);
                                rd = decimalToBinary(directionToGo - directionActual);
                                break;
                            }
                        }
                        rd = "0"+ rd;
                        binaryInstruction = rd.substr(0,1)+ rd.substr(2,6) +rs2+rs1+funct3+rd.substr(7,5)+rd.substr(1,1)+opCode;
                    }
                    
                    std::cout<<current->getData()<<std::endl;
                    std::cout<<binaryInstruction<<std::endl;
                    printBinaryToHex(binaryInstruction);
                    std::cout<<std::endl;
                    
                    found = true;
                    break; 
                }
            }
            current = current->getNext();
        }
    }
    
};

#endif

//-----------------------------------------------------------------------------------------
//---------------------------------- main function ----------------------------------------
//-----------------------------------------------------------------------------------------


using namespace std;

int main() {
    string nombreArchivo = "instrucciones.txt";
    ifstream archivo(nombreArchivo.c_str());
    
    // Verificar si se pudo abrir el archivo correctamente
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    
    List<string> lineas;
    string linea;
    
    while (getline(archivo, linea)) {
        lineas.push_back(linea);
    }
    
    archivo.close();
    
    //Definición de Clases
    std::vector<TipoInstruccion> listaTiposInstrucciones = preparacionDeClases();
    
    //Lista de procedimientos
    lineas.removeInvalidLines(listaTiposInstrucciones);
    lineas.assignMemoryAddresses();
    std::vector<std::pair<std::string, std::string>> labels = lineas.depurationLabel();
    lineas.print();
    lineas.traduccion(listaTiposInstrucciones, labels);
    
    return 0;
}