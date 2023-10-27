#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), target(copy.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    if (this != &copy)
    {
        this->AForm::operator=(copy);
    }
    return (*this);
}

std::string const &ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::ofstream fs((this->target + "_shrubbery").c_str());
    fs << "                                              ." << std::endl <<
    "                                   .         ;" << std::endl <<
    "      .              .              ;%     ;;" << std::endl <<
    "        ,           ,                :;%  %;" << std::endl <<
    "         :         ;                   :;%;'     .," << std::endl <<
    ",.        %;     %;            ;        %;'    ,;" << std::endl <<
    "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl <<
    "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl <<
    "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
    "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
    "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
    "         `:%;.  :;bd%;          %;@%;'" << std::endl <<
    "           `@%:.  :;%.         ;@@%;'" << std::endl <<
    "             `@%.  `;@%.      ;@@%;" << std::endl <<
    "               `@%%. `@%%    ;@@%;" << std::endl <<
    "                 ;@%. :@%%  %@@%;" << std::endl <<
    "                   %@bd%%%bd%%:;" << std::endl <<
    "                     #@%%%%%:;;" << std::endl <<
    "                     %@@%%%::;" << std::endl <<
    "                     %@@@%(o);  . '" << std::endl <<
    "                     %@@@o%;:(.,'" << std::endl <<
    "                 `.. %@@@o%::;" << std::endl <<
    "                    `)@@@o%::;" << std::endl <<
    "                     %@@(o)::;" << std::endl <<
    "                    .%@@@@%::;" << std::endl <<
    "                    ;%@@@@%::;." << std::endl <<
    "                   ;%@@@@%%:;;;." << std::endl <<
    "               ...;%@@@@@%%:;;;;,.." << std::endl;
    fs.close();
    std::cout << "Shrubbery created in " << this->target << "_shrubbery!" << std::endl;
}  
