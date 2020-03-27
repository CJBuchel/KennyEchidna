#include "webServer.h"

static struct mg_serve_http_opts s_http_server_opts;

// event handlder
static void ev_handler(struct mg_connection * nc, int ev, void *p) {
  // If ievent is http
  if (ev == MG_EV_HTTP_REQUEST) {
    // Serve static html files
    mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
  }
}

int initServer(int port, Comms *comms) {
  // Mogoose event manager
  struct mg_mgr mgr;
  // Mongoose connection
  struct mg_connection *nc;

  // Convert port to char
  std::string portToChar = std::to_string(port);
  static char const *sPort = portToChar.c_str();

  // Init mongoose
  mg_mgr_init(&mgr, NULL);
  std::cout << "Starting server on port: " << sPort << std::endl;

  nc = mg_bind(&mgr, sPort, ev_handler);
  // if con fail
  if (nc == NULL) {
    printf("\n Failed to create listener \n");
    comms->SetCommState(CommState::CON_FAULT);
    std::terminate();
  }

  // Set http server options
  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = "../../../UI/", // Directed to page directory
  s_http_server_opts.enable_directory_listing = "yes";

  while (comms->GetState() != CommState::STOPPED) {
    if (comms->GetState() == CommState::CON_FAULT) {
      break;
    } else {
      mg_mgr_poll(&mgr, 1000);
    }
  }

  // free up memory
  mg_mgr_free(&mgr);
  std::terminate();
}

void WebServer::ConnectServer(Comms *comms) {
  int port;
  std::cout << "Select server port: " << std::endl;
  std::cin >> port;

  // Fail case
  if (std::cin.fail()) {
    port = 1000;
  }

  std::thread webServer_t(initServer, port, comms);
  webServer_t.detach();
}