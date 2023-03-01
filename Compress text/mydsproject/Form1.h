#pragma once
#include "Mycode.h"
#include <string>
using namespace System::IO;


void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
	(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		String^ Path, ^ Pathsave;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ save;
	protected:

	protected:

	private: System::Windows::Forms::Button^ dcomp;

	protected:

	protected:

	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ comp;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->save = (gcnew System::Windows::Forms::Button());
			this->dcomp = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->comp = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// save
			// 
			this->save->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->save->Location = System::Drawing::Point(782, 358);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(77, 31);
			this->save->TabIndex = 0;
			this->save->Text = L"Save";
			this->toolTip1->SetToolTip(this->save, L"Click To Compress Your File");
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &Form1::comp_Click);
			// 
			// dcomp
			// 
			this->dcomp->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->dcomp->Location = System::Drawing::Point(105, 240);
			this->dcomp->Name = L"dcomp";
			this->dcomp->Size = System::Drawing::Size(164, 37);
			this->dcomp->TabIndex = 0;
			this->dcomp->Text = L"Decompress";
			this->toolTip1->SetToolTip(this->dcomp, L"Click To Decompress Your File");
			this->dcomp->UseVisualStyleBackColor = true;
			this->dcomp->Click += gcnew System::EventHandler(this, &Form1::dcomp_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->Tag = L"Click To Compress File";
			this->toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &Form1::toolTip1_Popup);
			// 
			// comp
			// 
			this->comp->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->comp->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comp->Location = System::Drawing::Point(105, 124);
			this->comp->Name = L"comp";
			this->comp->Size = System::Drawing::Size(164, 37);
			this->comp->TabIndex = 0;
			this->comp->Text = L"Compress";
			this->toolTip1->SetToolTip(this->comp, L"Click To Compress File");
			this->comp->UseVisualStyleBackColor = true;
			this->comp->Click += gcnew System::EventHandler(this, &Form1::comp_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Location = System::Drawing::Point(395, -3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(5, 401);
			this->panel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(408, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 2;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(408, 257);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 2;
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(550, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 29);
			this->label3->TabIndex = 3;
			this->label3->Text = L"File Data";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(408, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Original File";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(406, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(151, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Compressed File";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 372);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 17);
			this->label6->TabIndex = 5;
			this->label6->Text = L"About";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(90, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(225, 25);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Huffman Compression";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(861, 394);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->comp);
			this->Controls->Add(this->dcomp);
			this->Controls->Add(this->save);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolTip1_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comp_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ kl = this->label4->Text;
		string lp;
		MarshalString(kl, lp);
		
		Stream^ myStream;
		string pathsave,path;
		String  ^ Datasave;
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
		if (lp.size() == 13)
		{
			saveFileDialog1->Filter = "Huffman files (*.huf)|*.huf";
		}

		if (lp.size() == 15)
		{
			saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
		}

		saveFileDialog1->FilterIndex = 2;
		saveFileDialog1->RestoreDirectory = true;
		
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
			{
				Pathsave = gcnew String(saveFileDialog1->FileName);
				// Code to write the stream goes here.
				Datasave = "File Path: " + Pathsave + "\nFile Name: " ;
				myStream->Close();
			}
		}

		
		string str;
		MarshalString(Path, str);
		MarshalString(Pathsave, pathsave);

		huffman blak(str, pathsave);
		//MarshalString(kl, lp);
		if (lp.size()==13)
		{
			blak.compress();
		}

		if (lp.size()==15) 
		{
			blak.decompress();

		}
		

		string name = Filename(pathsave);
		Datasave = Datasave + gcnew String(name.c_str());
		int size2 = filesize(pathsave);
		Datasave = Datasave + "\nFile Size: " + size2.ToString() + " bytes";
		this->label2->Text = Datasave;
		this->save->Hide();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comp_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->label1->Text = "";
	this->label2->Text = "";
	this->label4->Text = "Original File";
	this->label5->Text = "Compressed File";
	Stream^ myStream;
	string path;
	String^Data;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	
	openFileDialog1->InitialDirectory = "C:\\Users\\M\\Downloads\\Compressed\\Ds-Semester-Project-main\\mydsproject\\";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			
			Path = openFileDialog1->FileName;
		Data = "File Path: " + Path+"\nFile Name: "+openFileDialog1->SafeFileName;
			myStream->Close();
		}
	};
	MarshalString(Path, path);
	int size=filesize(path);
	if (size==0)
	{
		MessageBox::Show("This File is Empty!\n");
		Application::Exit();
	}
	Data =Data+"\nFile Size: "+ size.ToString()+" bytes";
	this->label1->Text = Data;
	this->save->Show();

}
private: System::Void dcomp_Click(System::Object^ sender, System::EventArgs^ e) {
	this->label1->Text = "";
	this->label2->Text = "";
	this->label4->Text = "Compressed File";
	this->label5->Text = "Decompressed File";

	Stream^ myStream;
	string path;
	String^ Data;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "C:\\Users\\M\\Downloads\\Compressed\\Ds-Semester-Project-main\\mydsproject\\";
	openFileDialog1->Filter = "Huffman files (*.huf)|*.huf";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.

			Path = openFileDialog1->FileName;
			Data = "File Path: " + Path + "\nFile Name: " + openFileDialog1->SafeFileName;
			myStream->Close();
		}
	};
	MarshalString(Path, path);
	int size = filesize(path);
	if (size == 0)
	{
		MessageBox::Show("This File is Empty!\n");
		Application::Exit();
	}
	Data = Data + "\nFile Size: " + size.ToString() + " bytes";
	this->label1->Text = Data;
	this->save->Show();
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	
	MessageBox::Show("This Program is Strictly Copyrighted by the Owner!\nNo one is allowed to copy it unless Owner's Allows it. \n--OWNERS--\n->Furqan Ahmad\n->Ali Iqbal");
}
};
}




