// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENTMESSAGE_FTP_MESSAGES_CLIENT_H_
#define FLATBUFFERS_GENERATED_CLIENTMESSAGE_FTP_MESSAGES_CLIENT_H_

#include "flatbuffers/flatbuffers.h"

namespace FTP {
namespace Messages {
namespace Client {

struct ConnectionRequest;

struct ClientMessage;

enum Message {
  Message_NONE = 0,
  Message_ConnectionRequest = 1,
  Message_MIN = Message_NONE,
  Message_MAX = Message_ConnectionRequest
};

inline const char **EnumNamesMessage() {
  static const char *names[] = {
    "NONE",
    "ConnectionRequest",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessage(Message e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesMessage()[index];
}

template<typename T> struct MessageTraits {
  static const Message enum_value = Message_NONE;
};

template<> struct MessageTraits<ConnectionRequest> {
  static const Message enum_value = Message_ConnectionRequest;
};

bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type);
bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct ConnectionRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_FILEPATH = 4,
    VT_CHUNKS = 6
  };
  const flatbuffers::String *filepath() const {
    return GetPointer<const flatbuffers::String *>(VT_FILEPATH);
  }
  int16_t chunks() const {
    return GetField<int16_t>(VT_CHUNKS, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_FILEPATH) &&
           verifier.Verify(filepath()) &&
           VerifyField<int16_t>(verifier, VT_CHUNKS) &&
           verifier.EndTable();
  }
};

struct ConnectionRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_filepath(flatbuffers::Offset<flatbuffers::String> filepath) {
    fbb_.AddOffset(ConnectionRequest::VT_FILEPATH, filepath);
  }
  void add_chunks(int16_t chunks) {
    fbb_.AddElement<int16_t>(ConnectionRequest::VT_CHUNKS, chunks, 0);
  }
  ConnectionRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConnectionRequestBuilder &operator=(const ConnectionRequestBuilder &);
  flatbuffers::Offset<ConnectionRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<ConnectionRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<ConnectionRequest> CreateConnectionRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> filepath = 0,
    int16_t chunks = 0) {
  ConnectionRequestBuilder builder_(_fbb);
  builder_.add_filepath(filepath);
  builder_.add_chunks(chunks);
  return builder_.Finish();
}

inline flatbuffers::Offset<ConnectionRequest> CreateConnectionRequestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *filepath = nullptr,
    int16_t chunks = 0) {
  return CreateConnectionRequest(
      _fbb,
      filepath ? _fbb.CreateString(filepath) : 0,
      chunks);
}

struct ClientMessage FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TOKEN = 4,
    VT_MESSAGE_TYPE = 6,
    VT_MESSAGE = 8
  };
  const flatbuffers::String *token() const {
    return GetPointer<const flatbuffers::String *>(VT_TOKEN);
  }
  Message message_type() const {
    return static_cast<Message>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TOKEN) &&
           verifier.Verify(token()) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           VerifyMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

struct ClientMessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_token(flatbuffers::Offset<flatbuffers::String> token) {
    fbb_.AddOffset(ClientMessage::VT_TOKEN, token);
  }
  void add_message_type(Message message_type) {
    fbb_.AddElement<uint8_t>(ClientMessage::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(ClientMessage::VT_MESSAGE, message);
  }
  ClientMessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ClientMessageBuilder &operator=(const ClientMessageBuilder &);
  flatbuffers::Offset<ClientMessage> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<ClientMessage>(end);
    return o;
  }
};

inline flatbuffers::Offset<ClientMessage> CreateClientMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> token = 0,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  ClientMessageBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_token(token);
  builder_.add_message_type(message_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<ClientMessage> CreateClientMessageDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *token = nullptr,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  return CreateClientMessage(
      _fbb,
      token ? _fbb.CreateString(token) : 0,
      message_type,
      message);
}

inline bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type) {
  switch (type) {
    case Message_NONE: {
      return true;
    }
    case Message_ConnectionRequest: {
      auto ptr = reinterpret_cast<const ConnectionRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessage(
        verifier,  values->Get(i), types->GetEnum<Message>(i))) {
      return false;
    }
  }
  return true;
}

inline const FTP::Messages::Client::ClientMessage *GetClientMessage(const void *buf) {
  return flatbuffers::GetRoot<FTP::Messages::Client::ClientMessage>(buf);
}

inline bool VerifyClientMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<FTP::Messages::Client::ClientMessage>(nullptr);
}

inline void FinishClientMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<FTP::Messages::Client::ClientMessage> root) {
  fbb.Finish(root);
}

}  // namespace Client
}  // namespace Messages
}  // namespace FTP

#endif  // FLATBUFFERS_GENERATED_CLIENTMESSAGE_FTP_MESSAGES_CLIENT_H_
