#pragma once
#include<queue>
#include<iostream>
#include <string>
#include<vector>
#include<stack>
#include <ctime>
#include "clsDate.h"
using namespace std;
class clsQueueLine
{
	
private:
		string _Perfix="";
		int _TotalTickets;
		short _AverageServeTime = 0;
		std::string _Tickit;
		class clsTicket {
		private:
			short _Number=0;
			string _Perfix;
			string _TicketTime;
			short _WaitingClients = 0;
			short _AverageServeTime = 0;
			short _ExpectedServeTime = 0;
		public:
			clsTicket(string Perfix, short Number, short WaitingClients, short AverageServeTime) {
				_Perfix = Perfix;
				_Number = Number;
				_TicketTime = clsDate::GetSystemDateTimeString();
				_WaitingClients = WaitingClients;
				_AverageServeTime = AverageServeTime;
			}
			std::string Perfix() {
				return _Perfix;
			}
			short Number() {
				return _Number;
			}
			string FullNumber() {
				return _Perfix + to_string(_Number);
			}
			string TicketTime()
			{
				return _TicketTime;
			}

			short WaitingClients()
			{
				return _WaitingClients;
			}

			short ExpectedServeTime()
			{
				return _AverageServeTime * _WaitingClients;
			}

		};
	
	

public:
	std::queue<clsTicket> QueueLine;
	clsQueueLine(string Perfix,short AverageServeTime) {
		_Perfix = Perfix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}
	void IssueTickets() {
		_TotalTickets++;
		clsTicket Ticket(_Perfix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	}
	int WaitingClients() {
		return QueueLine.size();
	}
	std::string WhoIsNext() {
		if (QueueLine.empty()) {
			return "There is no cllient left\n";
		}
		else {
			return QueueLine.front().FullNumber();
		}
	}
	bool ServeNextClient() {
		if (QueueLine.empty()) {
			return false;
		}
		QueueLine.pop();
		return true;
	}
	short ServedClients() {
		return _TotalTickets - WaitingClients();
	}
	void PrintInfo() {
		std::cout << "\t\t\t_________________________\n\n";
		std::cout << "\t\t\tClient Information\n";
		std::cout << "\t\t\t_________________________\n\n";
		std::cout << "\t\t\tPerfix: "<< _Perfix;
		std::cout << "\n\t\t\tTotal Tickits: " << _TotalTickets;
		std::cout << "\n\t\t\tServed Clients: " << ServedClients();
		std::cout << "\n\t\t\tWaiting Clients: " << WaitingClients();
		std::cout << "\n\t\t\t_________________________\n\n\n";
		
	}
	void PrintTicketsRTL() {
		if (QueueLine.empty()) {
			std::cout << "No Tickets\n";
		}
		std::cout << "\t\t\tTickets: ";
		std::queue<clsTicket>TempQueueLine = QueueLine;
		while (!TempQueueLine.empty()) {
			clsTicket Ticket = TempQueueLine.front();
			std::cout << Ticket.FullNumber() << "<--";
			TempQueueLine.pop();
		}

		
	}
	void PrintTicketsLTR() {
		std::cout << "\n\n\t\t\tTickets: ";
		std::queue<clsTicket>TempQueueLine = QueueLine;
		std::stack<clsTicket>TempStackLine;
		while (!TempQueueLine.empty()) {
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}
		while (!TempStackLine.empty()) {
			clsTicket Ticket = TempStackLine.top();
			std::cout << Ticket.FullNumber()<<"-->";
			TempStackLine.pop();
		}
	}
	void PrintAllTickets() {
		if (QueueLine.empty()) {
			std::cout << "No Tickets\n";
		}
		std::cout << "\t\t\t         Tickets: ";
		std::queue<clsTicket>TempQueueLine = QueueLine;
		while (!TempQueueLine.empty()) {
			TempQueueLine.front();
			TempQueueLine.pop();
		}
	}


	
};

