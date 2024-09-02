/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-02 12:08:23
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-02 15:24:11
 * @FilePath: /action_ws/include/action_ws/books.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class Books {
    public:

     explicit Books(const std::string& name) {
        std::ifstream text;
        text.open("doc/" + name, std::ios::in);
        std::string inbuf;
        while(std::getline(text,inbuf)) {
            this->vec_lines.push_back(inbuf);
            this->total_lines++;
            if(text.eof()) {
                break;
            }
        }
        std::cout << "get total line:" << this->total_lines << std::endl;
        text.close();
      }

    std::string get_line_words(int cur_line) {
        if(cur_line > total_lines || cur_line <= 0) {
            return "";
        }
        return vec_lines[cur_line-1];
    }

    int get_total_line() const { return this->total_lines;}

    private:

      std::vector<std::string> vec_lines;
      int total_lines;

};