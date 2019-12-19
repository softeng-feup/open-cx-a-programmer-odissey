# openCX-a-programmer-odissey Development Report

Welcome to the documentation pages for Connection Connect a module of **openCX**!

You can find here detailed information about the module, from a high-level vision to low-level implementation decisions, a kind of Software Development Report (see [template](https://github.com/softeng-feup/open-cx/blob/master/docs/templates/Development-Report.md)), organized by discipline (as of RUP): 

* Business modeling 
  * [Product Vision](#Product-Vision)
  * [Elevator Pitch](#Elevator-Pitch)
* Requirements
  * [Use Case Diagram](#Use-case-diagram)
  * [User stories](#User-stories)
  * [Domain model](#Domain-model)
* Architecture and Design
  * [Architectural and design decisions]()
  * [Technological architecture]()
  * [Logical architecture]()
* Implementation
  * [Source code]()
  * [Issues](): feature requests, bug fixes, improvements.
* Test
  * [Automated tests](): Functional tests, integration tests, acceptance tests, as much automated as possible.
* Change management
  * [Issues at Github]()
* Project management
  * [Board at Github Projects](https://github.com/softeng-feup/open-cx-a-programmer-odissey/projects/1) 

So far, contributions are exclusively made by the initial team, but we hope to open them to the community, in all areas and topics: requirements, technologies, development, experimentation, testing, etc.

Please contact us! 

Thank you!

Made by:
 * Álvaro Francisco Barbosa Miranda
 * Gonçalo Santos Oliveira
 * João Filipe Carvalho de Araújo
 * Nuno Miguel Fernandes Marques
 * Pedro Alexandre Vieites Mendes

## Motivation
Interactions between people in a conference can get easily hampered: conferences are often hosted in an unknown place and the audience comes from all around the world. This means that, most times, it is hard to meet people who have similar interests and network with them without trying to talk to other people and then coming to the conclusion you have nothing in common with them. On the other hand, it is not uncommon to carry several copies of one's CV so as to deliver them to potential employees. Because of these problems, Conference Connect was born, a revolutionary smart badge that locates people with similar interests and connects people with businesses!

## Product Vision
Improve interactions between conference goers using the power of technology by offering them a networking platform where they can find people with similar interests and exchange information using a [micro:bit](https://microbit.org) powered smart badge.

## Elevator Pitch
This module allows for easy communication between participants in a conference and finding people with similar interests around each of them by using a small and lightweight device. 

## Requirements
This module requires each person participating in the conference to use a micro:bit and requires some information about the user, such as his personal information, his CV and his interests.

Start by contextualizing your module, describing the main concepts, terms, roles, scope and boundaries of the application domain addressed by the project.

### Use case diagram Imcomplete?
![Use cases](https://user-images.githubusercontent.com/2162852/67559084-2099d280-f710-11e9-9bbb-42d1b8b58b02.png)

Create a use-case diagram in UML with all high-level use cases possibly addressed by your module.

Give each use case a concise, results-oriented name. Use cases should reflect the tasks the user needs to be able to accomplish using the system. Include an action verb and a noun. 

Briefly describe each use case mentioning the following:

* **Actor**. Name only the actor that will be initiating this use case, i.e. a person or other entity external to the software system being specified who interacts with the system and performs use cases to accomplish tasks. 
* **Description**. Provide a brief description of the reason for and outcome of this use case, or a high-level description of the sequence of actions and the outcome of executing the use case. 
* **Preconditions and Postconditions**. Include any activities that must take place, or any conditions that must be true, before the use case can be started (preconditions) and postconditions. Describe also the state of the system at the conclusion of the use case execution (postconditions). 

* **Normal Flow**. Provide a detailed description of the user actions and system responses that will take place during execution of the use case under normal, expected conditions. This dialog sequence will ultimately lead to accomplishing the goal stated in the use case name and description. This is best done as a numbered list of actions performed by the actor, alternating with responses provided by the system. 
* **Alternative Flows and Exceptions**. Document other, legitimate usage scenarios that can take place within this use case, stating any differences in the sequence of steps that take place. In addition, describe any anticipated error conditions that could occur during execution of the use case, and define how the system is to respond to those conditions. 

### User stories Imcomplete?
### Must haves
* As an attendee, I want to be able to use the badge without having to download an app so that I don't have to reserve space on my phone for it. (Effort: L)
* As an attendee, I want to easily send my CV to potential employers. (Effort: S)
* As an attendee, I want to easily exchange contact information with other attendees. (Effort: S)

### Should haves
* As an attendee, I want my badge to notify me every time someone with similar interests to mine is near me so that I can have an easier time networking.
* As a lecturer, I want to survey my audience so that I can easily collect relevant information to my area or important to me.
* As a business, I want to know who is interested in my activities as well as information on who is looking for a job with me.


This section will contain the requirements of the product described as **user stories**, organized in a global **user story map** with **user roles** or **themes**.

For each theme, or role, you may add a small description here. User stories should be detailed in the tool you decided to use for project management (e.g. trello or github projects).

A user story is a description of desired functionality told from the perspective of the user or customer. A starting template for the description of a user story is 

*As a < user role >, I want < goal > so that < reason >.*

You add more details after, but the shorter and complete, the better. In order to decide if the user story is good, please follow the INVEST guidelines.

After the user story text, you should add a draft of the corresponding user interfaces, a simple mockups or drafts, if applicable.

For each user story you should write also the acceptance tests (textually in Gherkin), ie, a description of situations that will help to confirm that the system satisfies the requirements addressed in the user story.

At the end, it is good to add a rough indication of the value of the user story to the customers (e.g. MoSCoW method) and the team should add an estimative of the effort to implemente it, in t-shirt sizes (XS, S, M, L, XL).

### Domain model TODO

A simple UML class diagram with all the key concepts (names, attributes) and relationships involved of the problem domain addressed by your module.

---

## Architecture and Design
The main focus of our architecture is based on being able to use the micro:bit whithout requiring an application, this is achieved by comunicating with the PC using [serial port](https://github.com/softeng-feup/open-cx-a-programmer-odissey/tree/master/Serial%20Port) on a [server](https://github.com/softeng-feup/open-cx-a-programmer-odissey/tree/master/Microbit%20Programs/server) micro:bit, and by making the connection with [other](https://github.com/softeng-feup/open-cx-a-programmer-odissey/tree/master/Microbit%20Programs/client) micro:bits using the radio.

### Logical architecture TODO
The purpose of this subsection is to document the high-level logical structure of the code, using a UML diagram with logical packages, without the worry of allocating to components, processes or machines.

It can be beneficial to present the system both in a horizontal or vertical decomposition:
* horizontal decomposition may define layers and implementation concepts, such as the user interface, business logic and concepts; 
* vertical decomposition can define a hierarchy of subsystems that cover all layers of implementation.

### Physical architecture
![Physical Layer](https://github.com/softeng-feup/open-cx-a-programmer-odissey/blob/master/docs/Physical%20Layer.PNG)

We chose to use C++ while programming the microbit because it's a more lighweight language for the microbit in comparison to python and javascript and the microbit doesn't have much computing power. We also chose to use microbits using serial port with a PC for the servers because it made comunicating with the clients 

### Prototype TODO
To help on validating all the architectural, design and technological decisions made, we usually implement a vertical prototype, a thin vertical slice of the system.

In this subsection please describe in more detail which, and how, user(s) story(ies) were implemented.

---

## Implementation TODO
Regular product increments are a good practice of product management. 

While not necessary, sometimes it might be useful to explain a few aspects of the code that have the greatest potential to confuse software engineers about how it works. Since the code should speak by itself, try to keep this section as short and simple as possible.

Use cross-links to the code repository and only embed real fragments of code when strictly needed, since they tend to become outdated very soon.

---
## Test TODO

There are several ways of documenting testing activities, and quality assurance in general, being the most common: a strategy, a plan, test case specifications, and test checklists.

In this section it is only expected to include the following:
* test plan describing the list of features to be tested and the testing methods and tools;
* test case specifications to verify the functionalities, using unit tests and acceptance tests.
 
A good practice is to simplify this, avoiding repetitions, and automating the testing actions as much as possible.

---
## Configuration and change management

Configuration and change management are key activities to control change to, and maintain the integrity of, a project’s artifacts (code, models, documents).

For the purpose of ESOF, we will use a very simple approach, just to manage feature requests, bug fixes, and improvements, using GitHub issues and following the [GitHub flow](https://guides.github.com/introduction/flow/).


---

## Project management

[Board at Github Projects](https://github.com/softeng-feup/open-cx-a-programmer-odissey/projects/1) 

---

## Evolution - contributions to open-cx

There is no app so there is no possible integration
