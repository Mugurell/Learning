#pragma once
#include <cstdlib>
#include <ctime>



namespace SimpleRandomGeneratorApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace NAudio;
    using namespace NAudio::Wave;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::Button^  button3;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->SuspendLayout();
            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(865, 261);
            this->Name = L"MyForm";
            this->ResumeLayout(false);

        }
#pragma endregion

         // Generate button
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

    int num[6] = { 0 };

    // seed
    srand((int)time(0));

    // Randomize the array values.
    for (int i = 0; i < 6; i++)
        num[i] = (rand() % 99) + 1;

    // set the label text with random number
    this->label1->Text = Convert::ToString(num[0]);
    this->label2->Text = Convert::ToString(num[1]);
    this->label3->Text = Convert::ToString(num[2]);
    this->label4->Text = Convert::ToString(num[3]);
    this->label5->Text = Convert::ToString(num[4]);
    this->label6->Text = Convert::ToString(num[5]);

    // change the button states.
    this->button1->Enabled = false;
    this->button2->Enabled = true;
}



         // Reset button
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
     // clear label fields
     this->label1->Text = "0";
     this->label2->Text = "0";
     this->label3->Text = "0";
     this->label4->Text = "0";
     this->label5->Text = "0";
     this->label6->Text = "0";

     // set button state
     this->button1->Enabled = true;
     this->button2->Enabled = false;
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void fester(System::Object^  sender, System::EventArgs^  e) {
    IWavePlayer ^waveOutDevice = gcnew WaveOut();
    AudioFileReader ^audioFileReader = gcnew AudioFileReader("Fester.mp3");

    waveOutDevice->Init(audioFileReader);
    waveOutDevice->Play();
}
};
}
