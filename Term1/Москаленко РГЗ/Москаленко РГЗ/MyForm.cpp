#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    �������������::MyForm form;
    Application::Run(% form);
}

System::Void �������������::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    double value1, value2, value3;

    if (Double::TryParse(textBox1->Text, value1) && Double::TryParse(textBox2->Text, value2) && Double::TryParse(textBox3->Text, value3)) {

        double result = value2 * (value3 / 100) * (value1 / 360);
        double sum = value2 + result;

        label4->Text = String::Format("�����: {0:F2}", result);
        label5->Text = String::Format("���� � ���� ������ ������: {0:F2}", sum);

        label4->ForeColor = Color::Black;
        label5->ForeColor = Color::Black;
    }
    else {

        label4->Text = "������� ������� �����";
        label5->Text = "������� ������� �����";

        label4->ForeColor = Color::Red;
        label5->ForeColor = Color::Red;
    }
}