#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string.h>


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <winsock2.h>

#include <time.h>
#include <fstream>

#include "myo/myo.hpp"
#include "DataCollector.h"

#include "myo/libmyo.h"

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996) 

#define BUFLEN 512

#define SERVER "127.0.0.1"
#define PORT 7766

#pragma once
int EMG0;
int EMG1;
int EMG2;
int EMG3;
int EMG4;
int EMG5;
int EMG6;
int EMG7;

const char *char_EMG0;
const char *char_EMG1;
const char *char_EMG2;
const char *char_EMG3;
const char *char_EMG4;
const char *char_EMG5;
const char *char_EMG6;
const char *char_EMG7;

std::string string_EMG0;
std::string string_EMG1;
std::string string_EMG2;
std::string string_EMG3;
std::string string_EMG4;
std::string string_EMG5;
std::string string_EMG6;
std::string string_EMG7;

std::string letter_a = "a";
std::string letter_b = "b";
std::string letter_c = "c";
std::string letter_d = "d";
std::string letter_e = "e";
std::string letter_f = "f";
std::string letter_g = "g";
std::string letter_h = "h";
std::string temp_buffer;

const char *buffer;

bool Start_Send_Flag = 0;
bool Start_Save_To_File = 0;

std::fstream File;

uint8_t bat_level;

myo::Hub hub("com.mgr.myo_emg");
myo::Myo* my_myo;
DataCollector collector;

struct sockaddr_in servaddr, cliaddr;

int chart_x_size = 100;

int to_send;
int my_error_code;
SOCKET sock;
struct sockaddr_in sockaddr;
WSADATA wsa;
int i, j11, j2, j3, j4, j5, j6, j7, j8;

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

namespace MyoEMG {

	using namespace std;
	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();

			my_myo = hub.waitForMyo(10000);

			my_myo->setStreamEmg(myo::Myo::streamEmgEnabled);
			my_myo->requestBatteryLevel();
			my_myo->vibrate(myo::Myo::vibrationShort);
			hub.addListener(&collector);
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

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG1_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG2_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG3_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG4_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG5_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG6_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG7_chart;
	int i = 1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  EMG0_chart;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button_open_port;
	private: System::Windows::Forms::Button^  button_send;
	private: System::Windows::Forms::Label^  label_Message;
	private: System::Windows::Forms::Label^  label_Debug;
	private: System::Windows::Forms::Button^  button_Stop_Send;
	private: System::Windows::Forms::Button^  button_file_start;
	private: System::Windows::Forms::Button^  button_file_stop;
	private: System::Windows::Forms::Label^  label_File;
	private: System::Windows::Forms::Label^  label_buffer;
	public:
	private:
	private: System::ComponentModel::IContainer^  components;
	public:
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea8 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->EMG0_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->EMG1_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG2_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG3_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG4_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG5_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG6_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EMG7_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_open_port = (gcnew System::Windows::Forms::Button());
			this->button_send = (gcnew System::Windows::Forms::Button());
			this->label_Message = (gcnew System::Windows::Forms::Label());
			this->label_Debug = (gcnew System::Windows::Forms::Label());
			this->button_Stop_Send = (gcnew System::Windows::Forms::Button());
			this->button_file_start = (gcnew System::Windows::Forms::Button());
			this->button_file_stop = (gcnew System::Windows::Forms::Button());
			this->label_File = (gcnew System::Windows::Forms::Label());
			this->label_buffer = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG0_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG1_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG2_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG3_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG4_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG5_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG6_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG7_chart))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Wizualizacja sygna³ów EMG";
			// 
			// EMG0_chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->EMG0_chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->EMG0_chart->Legends->Add(legend1);
			this->EMG0_chart->Location = System::Drawing::Point(9, 22);
			this->EMG0_chart->Name = L"EMG0_chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Blue;
			series1->Legend = L"Legend1";
			series1->Name = L"EMG 0";
			this->EMG0_chart->Series->Add(series1);
			this->EMG0_chart->Size = System::Drawing::Size(467, 123);
			this->EMG0_chart->TabIndex = 2;
			this->EMG0_chart->Text = L"chart1";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1271, 523);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"00";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(971, 22);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(320, 45);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Wibracje opaski";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// EMG1_chart
			// 
			chartArea2->Name = L"ChartArea1";
			this->EMG1_chart->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->EMG1_chart->Legends->Add(legend2);
			this->EMG1_chart->Location = System::Drawing::Point(9, 152);
			this->EMG1_chart->Name = L"EMG1_chart";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Purple;
			series2->Legend = L"Legend1";
			series2->Name = L"EMG 1";
			this->EMG1_chart->Series->Add(series2);
			this->EMG1_chart->Size = System::Drawing::Size(467, 123);
			this->EMG1_chart->TabIndex = 6;
			this->EMG1_chart->Text = L"chart1";
			// 
			// EMG2_chart
			// 
			chartArea3->Name = L"ChartArea1";
			this->EMG2_chart->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->EMG2_chart->Legends->Add(legend3);
			this->EMG2_chart->Location = System::Drawing::Point(9, 282);
			this->EMG2_chart->Name = L"EMG2_chart";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Red;
			series3->Legend = L"Legend1";
			series3->Name = L"EMG 2";
			this->EMG2_chart->Series->Add(series3);
			this->EMG2_chart->Size = System::Drawing::Size(467, 123);
			this->EMG2_chart->TabIndex = 7;
			this->EMG2_chart->Text = L"chart2";
			// 
			// EMG3_chart
			// 
			chartArea4->Name = L"ChartArea1";
			this->EMG3_chart->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->EMG3_chart->Legends->Add(legend4);
			this->EMG3_chart->Location = System::Drawing::Point(9, 412);
			this->EMG3_chart->Name = L"EMG3_chart";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::Orange;
			series4->Legend = L"Legend1";
			series4->Name = L"EMG 3";
			this->EMG3_chart->Series->Add(series4);
			this->EMG3_chart->Size = System::Drawing::Size(467, 123);
			this->EMG3_chart->TabIndex = 8;
			this->EMG3_chart->Text = L"chart3";
			// 
			// EMG4_chart
			// 
			chartArea5->Name = L"ChartArea1";
			this->EMG4_chart->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			this->EMG4_chart->Legends->Add(legend5);
			this->EMG4_chart->Location = System::Drawing::Point(481, 22);
			this->EMG4_chart->Name = L"EMG4_chart";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Color = System::Drawing::Color::Brown;
			series5->Legend = L"Legend1";
			series5->Name = L"EMG 4";
			this->EMG4_chart->Series->Add(series5);
			this->EMG4_chart->Size = System::Drawing::Size(467, 123);
			this->EMG4_chart->TabIndex = 12;
			this->EMG4_chart->Text = L"chart4";
			this->EMG4_chart->Click += gcnew System::EventHandler(this, &MyForm::EMG4_chart_Click);
			// 
			// EMG5_chart
			// 
			chartArea6->Name = L"ChartArea1";
			this->EMG5_chart->ChartAreas->Add(chartArea6);
			legend6->Name = L"Legend1";
			this->EMG5_chart->Legends->Add(legend6);
			this->EMG5_chart->Location = System::Drawing::Point(481, 152);
			this->EMG5_chart->Name = L"EMG5_chart";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Color = System::Drawing::Color::DimGray;
			series6->Legend = L"Legend1";
			series6->Name = L"EMG 5";
			this->EMG5_chart->Series->Add(series6);
			this->EMG5_chart->Size = System::Drawing::Size(467, 123);
			this->EMG5_chart->TabIndex = 11;
			this->EMG5_chart->Text = L"chart5";
			// 
			// EMG6_chart
			// 
			chartArea7->Name = L"ChartArea1";
			this->EMG6_chart->ChartAreas->Add(chartArea7);
			legend7->Name = L"Legend1";
			this->EMG6_chart->Legends->Add(legend7);
			this->EMG6_chart->Location = System::Drawing::Point(481, 282);
			this->EMG6_chart->Name = L"EMG6_chart";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Color = System::Drawing::Color::Lime;
			series7->Legend = L"Legend1";
			series7->Name = L"EMG 6";
			this->EMG6_chart->Series->Add(series7);
			this->EMG6_chart->Size = System::Drawing::Size(467, 123);
			this->EMG6_chart->TabIndex = 10;
			this->EMG6_chart->Text = L"chart6";
			// 
			// EMG7_chart
			// 
			chartArea8->Name = L"ChartArea1";
			this->EMG7_chart->ChartAreas->Add(chartArea8);
			legend8->Name = L"Legend1";
			this->EMG7_chart->Legends->Add(legend8);
			this->EMG7_chart->Location = System::Drawing::Point(481, 412);
			this->EMG7_chart->Name = L"EMG7_chart";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Color = System::Drawing::Color::Green;
			series8->Legend = L"Legend1";
			series8->Name = L"EMG 7";
			this->EMG7_chart->Series->Add(series8);
			this->EMG7_chart->Size = System::Drawing::Size(467, 123);
			this->EMG7_chart->TabIndex = 9;
			this->EMG7_chart->Text = L"chart1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(966, 523);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Poziom baterii:";
			// 
			// button_open_port
			// 
			this->button_open_port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button_open_port->Location = System::Drawing::Point(971, 79);
			this->button_open_port->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button_open_port->Name = L"button_open_port";
			this->button_open_port->Size = System::Drawing::Size(320, 45);
			this->button_open_port->TabIndex = 14;
			this->button_open_port->Text = L"Otwórz port komunikacyjny";
			this->button_open_port->UseVisualStyleBackColor = true;
			this->button_open_port->Click += gcnew System::EventHandler(this, &MyForm::button_open_port_Click);
			// 
			// button_send
			// 
			this->button_send->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button_send->Location = System::Drawing::Point(971, 152);
			this->button_send->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button_send->Name = L"button_send";
			this->button_send->Size = System::Drawing::Size(320, 45);
			this->button_send->TabIndex = 17;
			this->button_send->Text = L"Rozpocznij wysy³anie";
			this->button_send->UseVisualStyleBackColor = true;
			this->button_send->Click += gcnew System::EventHandler(this, &MyForm::button_send_Click);
			// 
			// label_Message
			// 
			this->label_Message->AutoSize = true;
			this->label_Message->Location = System::Drawing::Point(969, 133);
			this->label_Message->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_Message->Name = L"label_Message";
			this->label_Message->Size = System::Drawing::Size(150, 13);
			this->label_Message->TabIndex = 18;
			this->label_Message->Text = L"Status portu komunikacyjnego";
			// 
			// label_Debug
			// 
			this->label_Debug->AutoSize = true;
			this->label_Debug->Location = System::Drawing::Point(969, 263);
			this->label_Debug->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_Debug->Name = L"label_Debug";
			this->label_Debug->Size = System::Drawing::Size(115, 13);
			this->label_Debug->TabIndex = 19;
			this->label_Debug->Text = L"Status wysy³ania ramki";
			// 
			// button_Stop_Send
			// 
			this->button_Stop_Send->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button_Stop_Send->Location = System::Drawing::Point(971, 208);
			this->button_Stop_Send->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button_Stop_Send->Name = L"button_Stop_Send";
			this->button_Stop_Send->Size = System::Drawing::Size(320, 45);
			this->button_Stop_Send->TabIndex = 20;
			this->button_Stop_Send->Text = L"Zatrzymaj wysy³anie";
			this->button_Stop_Send->UseVisualStyleBackColor = true;
			this->button_Stop_Send->Click += gcnew System::EventHandler(this, &MyForm::button_Stop_Send_Click);
			// 
			// button_file_start
			// 
			this->button_file_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button_file_start->Location = System::Drawing::Point(969, 282);
			this->button_file_start->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button_file_start->Name = L"button_file_start";
			this->button_file_start->Size = System::Drawing::Size(320, 45);
			this->button_file_start->TabIndex = 21;
			this->button_file_start->Text = L"Rozpocznij zapis do pliku";
			this->button_file_start->UseVisualStyleBackColor = true;
			this->button_file_start->Click += gcnew System::EventHandler(this, &MyForm::button_file_start_Click);
			// 
			// button_file_stop
			// 
			this->button_file_stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button_file_stop->Location = System::Drawing::Point(969, 337);
			this->button_file_stop->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button_file_stop->Name = L"button_file_stop";
			this->button_file_stop->Size = System::Drawing::Size(320, 45);
			this->button_file_stop->TabIndex = 22;
			this->button_file_stop->Text = L"Zatrzymaj zapis do pliku";
			this->button_file_stop->UseVisualStyleBackColor = true;
			this->button_file_stop->Click += gcnew System::EventHandler(this, &MyForm::button_file_stop_Click);
			// 
			// label_File
			// 
			this->label_File->AutoSize = true;
			this->label_File->Location = System::Drawing::Point(966, 393);
			this->label_File->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_File->Name = L"label_File";
			this->label_File->Size = System::Drawing::Size(105, 13);
			this->label_File->TabIndex = 23;
			this->label_File->Text = L"Status otwarcia pliku";
			// 
			// label_buffer
			// 
			this->label_buffer->AutoSize = true;
			this->label_buffer->Location = System::Drawing::Point(966, 412);
			this->label_buffer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_buffer->Name = L"label_buffer";
			this->label_buffer->Size = System::Drawing::Size(82, 13);
			this->label_buffer->TabIndex = 24;
			this->label_buffer->Text = L"Wys³ana ramka";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1303, 557);
			this->Controls->Add(this->label_buffer);
			this->Controls->Add(this->label_File);
			this->Controls->Add(this->button_file_stop);
			this->Controls->Add(this->button_file_start);
			this->Controls->Add(this->button_Stop_Send);
			this->Controls->Add(this->label_Debug);
			this->Controls->Add(this->label_Message);
			this->Controls->Add(this->button_send);
			this->Controls->Add(this->button_open_port);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->EMG4_chart);
			this->Controls->Add(this->EMG5_chart);
			this->Controls->Add(this->EMG6_chart);
			this->Controls->Add(this->EMG7_chart);
			this->Controls->Add(this->EMG3_chart);
			this->Controls->Add(this->EMG2_chart);
			this->Controls->Add(this->EMG1_chart);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->EMG0_chart);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Myo EMG";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG0_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG1_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG2_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG3_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG4_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG5_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG6_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EMG7_chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		EMG0_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG0_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG1_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG1_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG2_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG2_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG3_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG3_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG4_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG4_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG5_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG5_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG6_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG6_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		EMG7_chart->ChartAreas["ChartArea1"]->AxisY->Maximum = 150;
		EMG7_chart->ChartAreas["ChartArea1"]->AxisY->Minimum = -150;

		label2->Text = "Wczytywanie";
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		hub.run(1000 / 20);
		EMG0 = (int)collector.emgSamples[0];
		EMG1 = (int)collector.emgSamples[1];
		EMG2 = (int)collector.emgSamples[2];
		EMG3 = (int)collector.emgSamples[3];
		EMG4 = (int)collector.emgSamples[4];
		EMG5 = (int)collector.emgSamples[5];
		EMG6 = (int)collector.emgSamples[6];
		EMG7 = (int)collector.emgSamples[7];
		
		EMG0_chart->Series["EMG 0"]->Points->AddY(EMG0);
		if (EMG0_chart->Series["EMG 0"]->Points->Count == chart_x_size)
		{
			EMG0_chart->Series["EMG 0"]->Points->RemoveAt(0);
		}
		EMG1_chart->Series["EMG 1"]->Points->AddY(EMG1);
		if (EMG1_chart->Series["EMG 1"]->Points->Count == chart_x_size)
		{
			EMG1_chart->Series["EMG 1"]->Points->RemoveAt(0);
		}
		EMG2_chart->Series["EMG 2"]->Points->AddY(EMG2);
		if (EMG2_chart->Series["EMG 2"]->Points->Count == chart_x_size)
		{
			EMG2_chart->Series["EMG 2"]->Points->RemoveAt(0);
		}
		EMG3_chart->Series["EMG 3"]->Points->AddY(EMG3);
		if (EMG3_chart->Series["EMG 3"]->Points->Count == chart_x_size)
		{
			EMG3_chart->Series["EMG 3"]->Points->RemoveAt(0);
		}
		EMG4_chart->Series["EMG 4"]->Points->AddY(EMG4);
		if (EMG4_chart->Series["EMG 4"]->Points->Count == chart_x_size)
		{
			EMG4_chart->Series["EMG 4"]->Points->RemoveAt(0);
		}
		EMG5_chart->Series["EMG 5"]->Points->AddY(EMG5);
		if (EMG5_chart->Series["EMG 5"]->Points->Count == chart_x_size)
		{
			EMG5_chart->Series["EMG 5"]->Points->RemoveAt(0);
		}
		EMG6_chart->Series["EMG 6"]->Points->AddY(EMG6);
		if (EMG6_chart->Series["EMG 6"]->Points->Count == chart_x_size)
		{
			EMG6_chart->Series["EMG 6"]->Points->RemoveAt(0);
		}
		EMG7_chart->Series["EMG 7"]->Points->AddY(EMG7);
		if (EMG7_chart->Series["EMG 7"]->Points->Count == chart_x_size)
		{
			EMG7_chart->Series["EMG 7"]->Points->RemoveAt(0);
		}
		if (i < 50)
		{
			i++;
		}
		else
		{
			string bat_level_form_text_temp = to_string(collector.bat_level);
			String^ bat_level_form_text = gcnew String(bat_level_form_text_temp.c_str());
			label2->Text = bat_level_form_text;
			i = 0;
		}
		if (Start_Send_Flag)
		{
			string_EMG0 = std::to_string(EMG0+500);
			string_EMG1 = std::to_string(EMG1+500);
			string_EMG2 = std::to_string(EMG2+500);
			string_EMG3 = std::to_string(EMG3+500);
			string_EMG4 = std::to_string(EMG4+500);
			string_EMG5 = std::to_string(EMG5+500);
			string_EMG6 = std::to_string(EMG6+500);
			string_EMG7 = std::to_string(EMG7+500);

			for (int i = 0; i < 3 - (string_EMG0.length()); i++)
			{
				string_EMG0 = "0" + string_EMG0;
			}

			for (int i = 0; i < 3 - (string_EMG1.length()); i++)
			{
				string_EMG1 = "0" + string_EMG1;
			}

			for (int i = 0; i < 3 - (string_EMG2.length()); i++)
			{
				string_EMG2 = "0" + string_EMG2;
			}

			for (int i = 0; i < 3 - (string_EMG3.length()); i++)
			{
				string_EMG3 = "0" + string_EMG3;
			}

			for (int i = 0; i < 3 - (string_EMG4.length()); i++)
			{
				string_EMG4 = "0" + string_EMG4;
			}

			for (int i = 0; i < 3 - (string_EMG5.length()); i++)
			{
				string_EMG5 = "0" + string_EMG5;
			}
			
			for (int i = 0; i < 3 - (string_EMG6.length()); i++)
			{
				string_EMG6 = "0" + string_EMG6;
			}

			for (int i = 0; i < 3 - (string_EMG7.length()); i++)
			{
				string_EMG7 = "0" + string_EMG7;
			}

			char_EMG0 = string_EMG0.c_str();
			char_EMG1 = string_EMG1.c_str();
			char_EMG2 = string_EMG2.c_str();
			char_EMG3 = string_EMG3.c_str();
			char_EMG4 = string_EMG4.c_str();
			char_EMG5 = string_EMG5.c_str();
			char_EMG6 = string_EMG6.c_str();
			char_EMG7 = string_EMG7.c_str();

			temp_buffer = letter_a + char_EMG0 + letter_b + char_EMG1 + letter_c + char_EMG2 + letter_d + char_EMG3 + letter_e + char_EMG4 + letter_f + char_EMG5 + letter_g + char_EMG6 + letter_h + char_EMG7;

			buffer = temp_buffer.c_str();
			String^ str2 = gcnew String(temp_buffer.c_str());

			label_buffer->Text = String::Format(L"{0}", str2);

			my_error_code = sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
			if (my_error_code == SOCKET_ERROR)
			{
				label_Debug->Text = String::Format(L"Nie udalo sie wys³aæ ramki. Kod bledu: {0}", my_error_code.ToString());
			}
			else
			{
				label_Debug->Text = "wyslano linijke";
				temp_buffer = "";
				buffer = "";
			}
			
			if (Start_Save_To_File)
			{
				File << EMG0 << ", "<< EMG1 << ", " << EMG2 << ", " << EMG3 << ", " << EMG4 << ", " << EMG5 << ", " << EMG6 << ", " << EMG7 << "\n";
				label_File->Text = "zapisano linijke";
			}
			else if ((Start_Save_To_File == 0) && (File.is_open() == 1))
			{
				if (File.good())
				{
					File.close();
					label_File->Text = "zamknieto plik";
				}
				else
				{
					label_File->Text = "blad przy zamykaniu pliku";
				}
			}
		}
		else
		{

		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		my_myo->vibrate(myo::Myo::vibrationShort);
	}
	private: System::Void button_open_port_Click(System::Object^  sender, System::EventArgs^  e) {
		
		label_Message->Text = "INICJALIZACJA";
		if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
			label_Message->Text = String::Format(L"Nie udalo sie zainicjalizowac WinSock API. Kod bledu: {0}", WSAGetLastError());
		}
		else
		{
			label_Message->Text = "Udalo sie zainicjalizowac WinSock API";
		}

		//tworzenie gniazda do wysylania
		label_Message->Text = "Tworzenie gniazda do wysylania";
		if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
		{
			label_Message->Text = String::Format(L"Nie udalo sie stworzyc gniazda do wysylania. Kod bledu: {0}", WSAGetLastError());
		}
		else
		{
			label_Message->Text = "Udalo sie stworzyc gniazdo do wysylania";
		}

		//wypelnienie sockaddr_in send
		label_Message->Text = "Wypelnianie informacji o gniezdzie do wysylania";
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(SERVER);
		sockaddr.sin_port = htons(PORT);
		label_Message->Text = "Informacje o gniezdzie wypelnione";

		

		//bindowanie gniazda
		if (bind(sock, (struct sockaddr*) &sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
		{
			label_Message->Text = String::Format(L"Nie udalo sie zbindowac gniazda. Kod bledu: {0}", WSAGetLastError());
		}
		else
		{
			label_Message->Text = "Udalo sie zbindowac gniazdo";
		}

	}
private: System::Void button_send_Click(System::Object^  sender, System::EventArgs^  e) {
	Start_Send_Flag = 1;
	button_send->Enabled = 0;
	button_Stop_Send->Enabled = 1;
}
private: System::Void button_Stop_Send_Click(System::Object^  sender, System::EventArgs^  e) {
	Start_Send_Flag = 0;
	button_send->Enabled = 1;
	button_Stop_Send->Enabled = 0;
}
private: System::Void button_file_start_Click(System::Object^  sender, System::EventArgs^  e) {
	
	File.open("MYO.txt", ios::in | ios::out | ios::app);
	if (File.good())
	{
		Start_Save_To_File = 1;
		label_File->Text = "otworzono plik";
	}
	else
	{
		label_File->Text = "nie otwarto pliku";
	}
	button_file_start->Enabled = 0;
	button_file_stop->Enabled = 1;
}

private: System::Void button_file_stop_Click(System::Object^  sender, System::EventArgs^  e) {
	Start_Save_To_File = 0;
	button_file_start->Enabled = 1;
	button_file_stop->Enabled = 0;
}
private: System::Void EMG4_chart_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}